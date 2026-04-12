#include <bits/stdc++.h>

#ifdef DEBUG
#include <Mylib/Debug/debug.cpp>
#else
#define dump(...) ((void)0)
#endif

template <typename T, typename U>
bool chmin(T &a, const U &b){
  return (a > b ? a = b, true : false);
}

template <typename T, typename U>
bool chmax(T &a, const U &b){
  return (a < b ? a = b, true : false);
}

template <typename T, size_t N, typename U>
void fill_array(T (&a)[N], const U &v){
  std::fill((U*)a, (U*)(a + N), v);
}

template <typename T>
auto make_vector(int n, int m, const T &value){
  return std::vector<std::vector<T>>(n, std::vector<T>(m, value));
}

template <typename T>
std::ostream& operator<<(std::ostream &s, const std::vector<T> &a){
  for(auto it = a.begin(); it != a.end(); ++it){
    if(it != a.begin()) s << " ";
    s << *it;
  }
  return s;
}

template <typename T>
std::istream& operator>>(std::istream &s, std::vector<T> &a){
  for(auto &x : a) s >> x;
  return s;
}

/**
 * @title Modint
 * @docs mint.md
 */
template <int32_t M> class ModInt{
public:
  constexpr static int32_t MOD = M;
  uint32_t val;
  
  constexpr ModInt(): val(0){}
  constexpr ModInt(int64_t n){
    if(n >= M) val = n % M;
    else if(n < 0) val = n % M + M;
    else val = n;
  }
  
  constexpr auto& operator=(const ModInt &a){val = a.val; return *this;}
  constexpr auto& operator+=(const ModInt &a){
    if(val + a.val >= M) val = (uint64_t)val + a.val - M;
    else val += a.val;
    return *this;
  }
  constexpr auto& operator-=(const ModInt &a){
    if(val < a.val) val += M;
    val -= a.val;
    return *this;
  }
  constexpr auto& operator*=(const ModInt &a){
    val = (uint64_t)val * a.val % M;
    return *this;
  }
  constexpr auto& operator/=(const ModInt &a){
    val = (uint64_t)val * a.inv().val % M;
    return *this;
  }

  constexpr auto operator+(const ModInt &a) const {return ModInt(*this) += a;}
  constexpr auto operator-(const ModInt &a) const {return ModInt(*this) -= a;}
  constexpr auto operator*(const ModInt &a) const {return ModInt(*this) *= a;}
  constexpr auto operator/(const ModInt &a) const {return ModInt(*this) /= a;}
  
  constexpr bool operator==(const ModInt &a) const {return val == a.val;}
  constexpr bool operator!=(const ModInt &a) const {return val != a.val;}
  
  constexpr auto& operator++(){*this += 1; return *this;}
  constexpr auto& operator--(){*this -= 1; return *this;}
  
  constexpr auto operator++(int){auto t = *this; *this += 1; return t;}
  constexpr auto operator--(int){auto t = *this; *this -= 1; return t;}
  
  constexpr static ModInt power(int64_t n, int64_t p){
    if(p < 0) return power(n, -p).inv();
    
    int64_t ret = 1, e = n % M;
    for(; p; (e *= e) %= M, p >>= 1) if(p & 1) (ret *= e) %= M;
    return ret;
  }
  
  constexpr static ModInt inv(int64_t a){
    int64_t b = M, u = 1, v = 0;
    
    while(b){
      int64_t t = a / b;
      a -= t * b; std::swap(a,b);
      u -= t * v; std::swap(u,v);
    }
    
    u %= M;
    if(u < 0) u += M;
    
    return u;
  }
  
  constexpr static auto frac(int64_t a, int64_t b){return ModInt(a) / ModInt(b);}
  
  constexpr auto power(int64_t p) const {return power(val, p);}
  constexpr auto inv() const {return inv(val);}
  
  friend constexpr auto operator-(const ModInt &a){return ModInt(M-a.val);}
  
  friend constexpr auto operator+(int64_t a, const ModInt &b){return ModInt(a) + b;}
  friend constexpr auto operator-(int64_t a, const ModInt &b){return ModInt(a) - b;}
  friend constexpr auto operator*(int64_t a, const ModInt &b){return ModInt(a) * b;}
  friend constexpr auto operator/(int64_t a, const ModInt &b){return ModInt(a) / b;}
  
  friend std::istream& operator>>(std::istream &s, ModInt<M> &a){s >> a.val; return s;}
  friend std::ostream& operator<<(std::ostream &s, const ModInt<M> &a){s << a.val; return s;}

  template <int N>
  static auto div(){
    static auto value = inv(N);
    return value;
  }

  explicit operator int32_t() const noexcept {return val;}
  explicit operator int64_t() const noexcept {return val;}
};



namespace solver{
  void init(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    std::cerr << std::fixed << std::setprecision(12);
    std::cin.exceptions(std::ios_base::failbit);
  }

  using mint = ModInt<1000000007>;
  
  void solve(){
    int N; std::cin >> N;
    std::vector<int64_t> A(N); std::cin >> A;

    mint s = 0;
    for(auto x : A) s += x;

    mint ans = s * s;
    for(auto x : A) ans -= x * x;

    ans /= 2;

    std::cout << ans << "\n";
  }
}

int main(){
  solver::init();
  while(true){
    try{
      solver::solve();
    }catch(const std::istream::failure &e){
      break;
    }
  }
  return 0;
}
