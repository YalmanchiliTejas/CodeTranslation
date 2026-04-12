#include <bits/stdc++.h>
#include <atcoder/all>

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



namespace solver {
  namespace ac = atcoder;

  void init(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    std::cerr << std::fixed << std::setprecision(12);
    std::cin.exceptions(std::ios_base::failbit);
  }

  int op(int a, int b){return std::max(a, b);}
  int e(){return -1;}

  void solve(){
    int N, Q; std::cin >> N >> Q;
    std::vector<int> a(N); std::cin >> a;
    auto seg = ac::segtree<int, op, e>(a);

    for(int i = 0; i < Q; ++i){
      int type; std::cin >> type;

      if(type == 1){
        int x, v; std::cin >> x >> v;
        seg.set(x - 1, v);
      }else if(type == 2){
        int l, r; std::cin >> l >> r;
        std::cout << seg.prod(l - 1, r) << "\n";
      }else{
        int x, v; std::cin >> x >> v;
        std::cout << seg.max_right(x - 1, [v](int x){return x < v;}) + 1 << "\n";
      }
    }
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
