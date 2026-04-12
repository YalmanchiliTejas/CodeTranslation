#include <bits/stdc++.h>
#ifdef __LOCAL
    #define DBG(X) cout << #X << " = " << (X) << endl;
    #define SAY(X) cout << (X) << endl;
#else
    #define DBG(X)
    #define SAY(X)
#endif

#ifdef __LOCAL
    #include <filesystem>
    namespace fs = std::filesystem;
#endif

using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const map<T, S> p) { for (auto el : p) os << "[" << el.first << " " << el.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for (auto el : v) os << el << " "; return os; }
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for (auto& elem : ret) cin >> elem; return ret; }


template< typename Monoid, typename OperatorMonoid = Monoid >
struct LazySegmentTree {
  using F = function< Monoid(Monoid, Monoid) >;
  using G = function< Monoid(Monoid, OperatorMonoid) >;
  using H = function< OperatorMonoid(OperatorMonoid, OperatorMonoid) >;

  int sz, height;
  vector< Monoid > data;
  vector< OperatorMonoid > lazy;
  const F f;
  const G g;
  const H h;
  const Monoid M1;
  const OperatorMonoid OM0;


  LazySegmentTree(int n, const F f, const G g, const H h,
                  const Monoid &M1, const OperatorMonoid OM0)
      : f(f), g(g), h(h), M1(M1), OM0(OM0) {
    sz = 1;
    height = 0;
    while(sz < n) sz <<= 1, height++;
    data.assign(2 * sz, M1);
    lazy.assign(2 * sz, OM0);
  }

  void set(int k, const Monoid &x) {
    data[k + sz] = x;
  }

  void build() {
    for(int k = sz - 1; k > 0; k--) {
      data[k] = f(data[2 * k + 0], data[2 * k + 1]);
    }
  }

  inline void propagate(int k) {
    if(lazy[k] != OM0) {
      lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
      lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
      data[k] = reflect(k);
      lazy[k] = OM0;
    }
  }

  inline Monoid reflect(int k) {
    return lazy[k] == OM0 ? data[k] : g(data[k], lazy[k]);
  }

  inline void recalc(int k) {
    while(k >>= 1) data[k] = f(reflect(2 * k + 0), reflect(2 * k + 1));
  }

  inline void thrust(int k) {
    for(int i = height; i > 0; i--) propagate(k >> i);
  }

  void update(int a, int b, const OperatorMonoid &x) {
    thrust(a += sz);
    thrust(b += sz - 1);
    for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if(l & 1) lazy[l] = h(lazy[l], x), ++l;
      if(r & 1) --r, lazy[r] = h(lazy[r], x);
    }
    recalc(a);
    recalc(b);
  }

  Monoid query(int a, int b) {
    thrust(a += sz);
    thrust(b += sz - 1);
    Monoid L = M1, R = M1;
    for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if(l & 1) L = f(L, reflect(l++));
      if(r & 1) R = f(reflect(--r), R);
    }
    return f(L, R);
  }

  Monoid operator[](const int &k) {
    return query(k, k + 1);
  }
};


int N,M;

struct Interval{
    int l,r;
    int a;
    Interval(int l,int r, ll a):l(l),r(r),a(a){}
};

vector<Interval> Intervals;
unordered_map<int,vector<pair<int,ll> > > right_left_score;

void input(){
    fast_io();
    #ifdef __LOCAL
        fs::path p = __FILE__;
        fs::path input,output;
        input = output = p.parent_path();
        input += string("/input/") + string(p.stem()) + string(".txt");
        output += string("/output/") + string(p.stem()) + string(".txt");
        freopen(input.c_str(), "r", stdin);
        freopen(output.c_str(), "w", stdout);
    #endif
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int l,r;
        ll a;
        cin >> l >> r >> a;
        l--,r--;
        Intervals.emplace_back(l,r,a);
        right_left_score[r].emplace_back(l,a);
    }
    sort(Intervals.begin(),Intervals.end(),[](Interval a, Interval b){return a.r < b.r;});    
}


int solve(){
  auto f = [](ll a, ll b) { return max(a, b); };
  auto g = [](ll a, ll b) { return a + b; };
  auto h = [](ll a, ll p) { return a + p; };
 
  LazySegmentTree< ll > seg(N+2, f, g, h, 0, 0);
  for (int i = 0; i < N; i++)
  {
    if(i) seg.update(i,i+1,seg.query(0,i));
    for(auto left_score:right_left_score[i]){
      seg.update(left_score.first,i+1,left_score.second);
    }
  }
  cout << seg.query(0,N+1) << endl;

  return 0;
}

int main()
{
    input();
    solve();
    return 0;
}
