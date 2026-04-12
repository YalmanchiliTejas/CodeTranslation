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

template <typename T, size_t N, size_t I = N>
auto make_vector(const std::array<int, N> &a, T value = T()){
  static_assert(I >= 1);
  static_assert(N >= 1);
  if constexpr (I == 1){
    return std::vector<T>(a[N - I], value);
  }else{
    return std::vector(a[N - I], make_vector<T, N, I - 1>(a, value));
  }
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

template <typename F>
std::pair<int, int> rho(int N, int first, F f){
  std::vector<int> check(N);

  int tail = 0, cycle = 0;
  int a = first, i = 1;
  while(true){
    check[a] = i;

    a = f(a);
    ++i;
    if(check[a] > 0){
      tail = check[a] - 1;
      cycle = i - check[a];
      break;
    }
  }

  return {tail, cycle};
}


namespace haar_lib {}

namespace solver {
  using namespace haar_lib;

  constexpr int m1000000007 = 1000000007;
  constexpr int m998244353 = 998244353;

  void init(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    std::cerr << std::fixed << std::setprecision(12);
    std::cin.exceptions(std::ios_base::failbit);
  }

  void solve(){
    int64_t N, X, M; std::cin >> N >> X >> M;

    auto [tail, cycle] = rho(M, X, [M](int64_t a){return a * a % M;});

    int64_t ans = 0;

    if(N <= tail){
      int64_t a = X;
      for(int i = 0; i < N; ++i){
        ans += a;
        a = a * a % M;
      }
    }else{
      int64_t a = X;
      for(int i = 0; i < tail; ++i){
        ans += a;
        a = a * a % M;
      }

      N -= tail;

      {
        int64_t b = a, s = 0;
        for(int i = 0; i < cycle; ++i){
          s += b;
          b = b * b % M;
        }

        ans += s * (N / cycle);
      }

      {
        int64_t b = a;
        for(int i = 0; i < N % cycle; ++i){
          ans += b;
          b = b * b % M;
        }
      }
    }

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
