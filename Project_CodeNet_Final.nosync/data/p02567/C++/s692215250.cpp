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


namespace haar_lib {
  template <typename T>
  struct bounded_max_monoid {
    using value_type = T;

    value_type operator()() const {return std::numeric_limits<T>::lowest();}
    value_type operator()(const value_type &a, const value_type &b) const {
      return std::max(a, b);
    }
  };
}




/**
 * @title Segment tree
 * @docs segment_tree.md
 */
namespace haar_lib {
  template <typename Monoid>
  class segment_tree {
    using value_type = typename Monoid::value_type;
    const static Monoid M;

    int depth, size, hsize;
    std::vector<value_type> data;

  public:
    segment_tree(){}
    segment_tree(int n):
      depth(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),
      size(1 << depth), hsize(size / 2),
      data(size, M())
    {}

    auto operator[](int i) const {return data[hsize + i];}

    auto get(int x, int y) const {
      value_type ret_left = M();
      value_type ret_right = M();

      int l = x + hsize, r = y + hsize;
      while(l < r){
        if(r & 1) ret_right = M(data[--r], ret_right);
        if(l & 1) ret_left = M(ret_left, data[l++]);
        l >>= 1, r >>= 1;
      }

      return M(ret_left, ret_right);
    }

    void update(int i, const value_type &x){
      i += hsize;
      data[i] = x;
      while(i > 1) i >>= 1, data[i] = M(data[i << 1 | 0], data[i << 1 | 1]);
    }

    template <typename T>
    void init_with_vector(const std::vector<T> &val){
      data.assign(size, M());
      for(int i = 0; i < (int)val.size(); ++i) data[hsize + i] = val[i];
      for(int i = hsize - 1; i >= 1; --i) data[i] = M(data[i << 1 | 0], data[i << 1 | 1]);
    }

    template <typename T>
    void init(const T &val){
      init_with_vector(std::vector<value_type>(hsize, val));
    }

    template <bool Lower, typename F>
    int bound(const int l, const int r, value_type x, F f) const {
      std::vector<int> pl, pr;
      int L = l + hsize;
      int R = r + hsize;
      while(L < R){
        if(R & 1) pr.push_back(--R);
        if(L & 1) pl.push_back(L++);
        L >>= 1, R >>= 1;
      }

      std::reverse(pr.begin(), pr.end());
      pl.insert(pl.end(), pr.begin(), pr.end());

      value_type a = M();

      for(int i : pl){
        auto b = M(a, data[i]);

        if((Lower and not f(b, x)) or (not Lower and f(x, b))){
          while(i < hsize){
            if(auto c = M(a, data[i << 1 | 0]); (Lower and not f(c, x)) or (not Lower and f(x, c))){
              i = i << 1 | 0;
            }else{
              a = c;
              i = i << 1 | 1;
            }
          }

          return i - hsize;
        }

        a = b;
      }

      return r;
    }

    template <typename F = std::less<value_type>>
    int lower_bound(int l, int r, value_type x, F f = F()) const {
      return bound<true>(l, r, x, f);
    }

    template <typename F = std::less<value_type>>
    int upper_bound(int l, int r, value_type x, F f = F()) const {
      return bound<false>(l, r, x, f);
    }
  };
}


namespace solver {
  using namespace haar_lib;

  void init(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    std::cerr << std::fixed << std::setprecision(12);
    std::cin.exceptions(std::ios_base::failbit);
  }

  void solve(){
    int N, Q; std::cin >> N >> Q;
    std::vector<int> a(N); std::cin >> a;
    auto seg = segment_tree<bounded_max_monoid<int>>(N);
    seg.init_with_vector(a);

    for(int i = 0; i < Q; ++i){
      int type; std::cin >> type;

      if(type == 1){
        int x, v; std::cin >> x >> v;
        seg.update(x - 1, v);
      }else if(type == 2){
        int l, r; std::cin >> l >> r;
        std::cout << seg.get(l - 1, r) << "\n";
      }else{
        int x, v; std::cin >> x >> v;
        std::cout << seg.lower_bound(x - 1, N, v) + 1 << "\n";
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
