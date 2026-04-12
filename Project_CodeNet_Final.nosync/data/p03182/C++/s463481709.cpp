#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<ll>;
using VV = vector<VI>;
using VS = vector<string>;
using PII = pair<ll, ll>;

// tourist set
template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << '\n'; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
// tourist set end

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i,b) FOR(i, 0, b)
#define ALL(v) (v).begin(), (v).end()
#define p(s) cout<<(s)<<'\n'
#define p2(s, t) cout << (s) << " " << (t) << '\n'
#define br() p("")
#define pn(s) cout << (#s) << " " << (s) << '\n'
#define p_yes() p("YES")
#define p_no() p("NO")
#define SZ(x) ((int)(x).size())
#define SORT(A) sort(ALL(A))
#define RSORT(A) sort(ALL(A), greater<ll>())
#define MP make_pair

void no(){p_no(); exit(0);}
void yes(){p_yes(); exit(0);}

const ll mod = 1e9 + 7;
const ll inf = 1e18;
const double PI = acos(-1);

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
//#define rep(i, n) repr(i, 0, n)
#define reprrev(i, a, b) for (int i = (int)(b)-1; i >= (int)(a); i--)
#define reprev(i, n) reprrev(i, 0, n)
// 遅延伝播セグ木
template <class T, class U>
class LazySegTree {
    /*
    区間更新・区間和
    auto operation = [](ll a, ll b) { return a + b; };
    auto adapt_lazy = [](ll a, ll b) { return b; };
    auto merge_lazy = [](ll a, ll b) { return b; };
    auto multiply_lazy = [](ll a, int n) { return a * n; };
 
    区間加算・区間和
    auto operation = [](ll a, ll b) { return a + b; };
    auto adapt_lazy = [](ll a, ll b) { return a + b; };
    auto merge_lazy = [](ll a, ll b) { return a + b; };
    auto multiply_lazy = [](ll a, int n) { return a * n; };
 
    区間更新・区間最小
    auto operation = [](ll a, ll b) { return min(a, b); };
    auto adapt_lazy = [](ll a, ll b) { return b; };
    auto merge_lazy = [](ll a, ll b) { return b; };
    auto multiply_lazy = [](ll a, int n) { return a; };
 
    区間加算・区間最小
    auto operation = [](ll a, ll b) { return min(a, b); };
    auto adapt_lazy = [](ll a, ll b) { return a + b; };
    auto merge_lazy = [](ll a, ll b) { return a + b; };
    auto multiply_lazy = [](ll a, int n) { return a; };
    */
    int n;
    vector<T> dat;
    vector<U> lazy;
    vector<int> width;
 
    function<T(T, T)> operation;
    function<T(T, U)> adapt_lazy;
    function<U(U, U)> merge_lazy;
    function<U(U, int)> multiply_lazy;
 
    T init, def, lazy_def;
 
    // ツリー上のノード k に lazy 値 v をセット
    void set_lazy(int k, U v) {
        if (lazy[k] == lazy_def) {
            lazy[k] = v;
            dat[k] = adapt_lazy(dat[k], multiply_lazy(v, width[k]));
        } else {
            lazy[k] = merge_lazy(lazy[k], v);
            dat[k] = adapt_lazy(dat[k], multiply_lazy(v, width[k]));
        }
    }
    // lazy を 1 段下ろす
    void push(int k) {
        if (lazy[k] == lazy_def) return;
        set_lazy(k * 2 + 1, lazy[k]);
        set_lazy(k * 2 + 2, lazy[k]);
        lazy[k] = lazy_def;
    }
 
    // 区間[a,b)の区間クエリ。ノードk=[l,r)に着目している。
    long long _query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return def; // 交差しない
        if (a <= l && r <= b) return dat[k]; // a,l,r,bの順で完全に含まれる
        push(k);
        long long c1 = _query(a, b, 2 * k + 1, l, (l + r) / 2); // 左の子
        long long c2 = _query(a, b, 2 * k + 2, (l + r) / 2, r); // 右の子
        return operation(c1, c2);
    }
 
  public:
    // _n:必要サイズ, _def:初期値, _operation:クエリ関数,
    // _adapt_lazy:区間作用素適用関数, _merge_lazy:区間作用素マージ関数,
    // _multiply_lazy:作用素を要素数で変形
    LazySegTree(size_t _n, T _init, T _def, T _lazy_def,
                function<T(T, T)> _operation, function<T(T, U)> _adapt_lazy,
                function<U(U, U)> _merge_lazy,
                function<U(U, int)> _multiply_lazy = [](U u,
                                                        int n) { return u; })
        : init(_init), def(_def), lazy_def(_lazy_def), operation(_operation),
          adapt_lazy(_adapt_lazy), merge_lazy(_merge_lazy),
          multiply_lazy(_multiply_lazy) {
        n = 1;
        while (n < _n) n *= 2;
        dat = vector<long long>(2 * n - 1, init);
        lazy = vector<long long>(2 * n - 1, lazy_def);
        width = vector<int>(2 * n - 1);
        width[0] = n;
        repr(i, 1, 2 * n - 1) width[i] = width[(i - 1) / 2] / 2;
    }
 
    // 区間[a,b)にvを作用させる
    void range_operation(int a, int b, long long v, int k = 0, int l = 0,
                         int r = -1) {
        if (r == -1) r = n;
        if (r <= a || b <= l) return; // 交差しない
        if (a <= l && r <= b) {       // a,l,r,bの順で完全に含まれる
            set_lazy(k, v);
            return;
        }
        push(k);
        range_operation(a, b, v, 2 * k + 1, l, (l + r) / 2); // 左の子
        range_operation(a, b, v, 2 * k + 2, (l + r) / 2, r); // 右の子
        dat[k] = operation(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
 
    // [a, b)の区間クエリを実行
    long long query(int a, int b) {
        return _query(a, b, 0, 0, n);
    }
 
    //  添字でアクセス
    long long operator[](int i) {
        return query(i, i + 1);
    }
};

vector<vector<PII>> V;

ll dp[200010];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    ll N, M;
    cin >> N >> M;
    V.resize(N);

    // ふるやんさんのセグ木
    // https://atcoder.jp/contests/dp/submissions/8327555
    auto operation = [](ll a, ll b) { return max(a, b); };
    auto adapt_lazy = [](ll a, ll b) { return a + b; };
    auto merge_lazy = [](ll a, ll b) { return a + b; };
    auto multiply_lazy = [](ll a, int n) { return a; };
    LazySegTree<ll, ll> seg(N + 1, 0, -inf, 0, operation, adapt_lazy,
                           merge_lazy, multiply_lazy);

    rep(i, M){
      ll l,r,a;
      cin>>l>>r>>a;
      l--; r--;
      V[r].push_back(MP(l,a));
    }

    rep(i, N){      
      // 半開区間
      ll ma = max(0LL, seg.query(0, i)); // i-1までのma (全部負かもしれないので0とmaxとる)
      seg.range_operation(i, i+1, ma);

      // そこが右端の範囲を全部反映
      for(auto pa : V[i]){
        ll right = i;
        ll left = pa.first;
        ll a = pa.second;
        seg.range_operation(left, right+1, a);
      }
    }

    ll ans = 0;
    rep(i, N){
      chmax(ans, seg[i]);
    }
    p(ans);
    
    return 0;
}