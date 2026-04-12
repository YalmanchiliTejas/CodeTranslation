#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdint>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <sys/timeb.h>
#include <vector>

using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define reprrev(i, a, b) for (int i = (int)(b)-1; i >= (int)(a); i--)
#define reprev(i, n) reprrev(i, 0, n)
#define repi(itr, ds) for (auto itr = ds.begin(); itr != ds.end(); itr++)
#define chmin(mi, value) mi = min(mi, value)
#define chmax(ma, value) ma = max(ma, value)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define mp make_pair
#define mt make_tuple
#define INF 1050000000
#define INFR INT_MAX
#define INFL (long long)(4e18)
#define INFLR LLONG_MAX
#define EPS (1e-10)
#define MOD 1000000007
//#define MOD 998244353
#define PI 3.141592653589793238
#define RMAX 4294967295

using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;
using vvvvi = vector<vector<vector<vector<int>>>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vvvll = vector<vector<vector<ll>>>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using vvvd = vector<vector<vector<double>>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vc = vector<char>;
using vvc = vector<vector<char>>;
using vs = vector<string>;
using vvs = vector<vector<string>>;
using Pi = pair<int, int>;
using vPi = vector<Pi>;
using vvPi = vector<vector<Pi>>;
using vvvPi = vector<vector<vector<Pi>>>;
using vvvvPi = vector<vector<vector<vector<Pi>>>>;
using Pll = pair<ll, ll>;
using vPll = vector<Pll>;
using Pd = pair<double, double>;
using vPd = vector<Pd>;
template <class T>
using vec = vector<T>;
template <class T>
using pql = priority_queue<T, vector<T>, greater<T>>;
using Comp = complex<double>;

// vvvvvvvvvvvvvvvvvvvvvvv debug output vvvvvvvvvvvvvvvvvvvvvvv
// vector input
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (T &x : vec) is >> x;
    return is;
}
// pair
template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &pair_var) {
    os << "(" << pair_var.first << ", " << pair_var.second << ")";
    return os;
}
// vector
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
    os << "{";
    for (int i = 0; i < vec.size(); i++) {
        os << vec[i] << (i + 1 == vec.size() ? "" : ", ");
    }
    os << "}";
    return os;
}
// deque
template <typename T>
ostream &operator<<(ostream &os, const deque<T> &vec) {
    os << "{";
    for (int i = 0; i < vec.size(); i++) {
        os << vec[i] << (i + 1 == vec.size() ? "" : ", ");
    }
    os << "}";
    return os;
}
// map
template <typename T, typename U>
ostream &operator<<(ostream &os, const map<T, U> &map_var) {
    os << "{";
    repi(itr, map_var) {
        os << *itr;
        itr++;
        if (itr != map_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}
// set
template <typename T>
ostream &operator<<(ostream &os, const set<T> &set_var) {
    os << "{";
    repi(itr, set_var) {
        os << *itr;
        itr++;
        if (itr != set_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}
// multiset
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &set_var) {
    os << "{";
    repi(itr, set_var) {
        os << *itr;
        itr++;
        if (itr != set_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}

#define DUMPOUT cerr

void dump_func() {
    DUMPOUT << endl;
}
template <class Head, class... Tail>
void dump_func(Head &&head, Tail &&... tail) {
    DUMPOUT << head;
    if (sizeof...(Tail) > 0) {
        DUMPOUT << ", ";
    }
    dump_func(std::move(tail)...);
}
#ifdef DEBUG_
#define DEB
#define dump(...)                                                              \
    DUMPOUT << "  " << string(#__VA_ARGS__) << ": "                            \
            << "[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]"        \
            << endl                                                            \
            << "    ",                                                         \
        dump_func(__VA_ARGS__)
#else
#define DEB if (false)
#define dump(...)
#endif

// ^^^^^^^^^^^^^^^^^^^^^^^ debug output ^^^^^^^^^^^^^^^^^^^^^^^

string YN(bool y, int id = 0) {
    if (id) cout << id;
    return (y ? "YES" : "NO");
}
string yn(bool y, int id = 0) {
    if (id) cout << id;
    return (y ? "Yes" : "No");
}
string ON(bool y, int id = 0) {
    if (id) cout << id;
    return (y ? "OK" : "NG");
}

int dir4[4][2] = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
int dir8[8][2] = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0},
                  {1, 0},   {-1, 1}, {0, 1},  {1, 1}};

// [a,b)
int irand(int a, int b) {
    static mt19937 Rand(static_cast<unsigned int>(time(nullptr)));
    uniform_int_distribution<int> dist(a, b - 1);
    return dist(Rand);
}

// [a,b)
double drand(int a, int b) {
    static mt19937 Rand(static_cast<unsigned int>(time(nullptr)));
    uniform_real_distribution<double> dist(a, b);
    return dist(Rand);
}

// https://qiita.com/IgnorantCoder/items/3101d6276e9bdddf872c
template <typename A, typename F>
inline auto transform(const A &v, F &&f) {
    using result_type =
        decltype(std::declval<F>()(std::declval<typename A::value_type>()));
    vector<result_type> y(v.size());
    std::transform(std::cbegin(v), std::cend(v), std::begin(y), f);
    return y;
}

// generate vector which has multiple dimension
template <class T>
vector<T> make_v(size_t size, const T &init) {
    return vector<T>(size, init);
}
template <class... Ts>
auto make_v(size_t size, Ts... rest) {
    return vector<decltype(make_v(rest...))>(size, make_v(rest...));
}

template <typename T>
T Max(vector<T> a) {
    return *max_element(all(a));
}
template <typename T>
T Min(vector<T> a) {
    return *min_element(all(a));
}
template <typename T>
T Sum(vector<T> a) {
    return accumulate(all(a), (T)0);
}

// for counting using map
template <typename T>
void Add(map<T, int> &m, T item) {
    if (m.find(item) == m.end()) {
        m[item] = 1;
    } else {
        m[item]++;
    }
}

// for counting using map
template <typename T>
void Erase(map<T, int> &m, T item) {
    if (m.find(item) == m.end()) {
    } else {
        if (m[item] == 1) {
            m.erase(item);
        } else {
            m[item]--;
        }
    }
}

// get method for map with default value
template <typename T, typename U>
U Get(map<T, U> m, T key, U def) {
    if (m.find(key) == m.end()) {
        return def;
    } else {
        return m[key];
    }
}

template <typename T>
inline bool Contains(const set<T> &t, const T &key) {
    return t.find(key) != t.end();
}

template <typename T, typename U>
inline bool Contains(const map<T, U> &t, const T &key) {
    return t.find(key) != t.end();
}

template <class T>
struct Edge {
    int from, to;
    T cost;
    Edge(int f, int t, T c) : from(f), to(t), cost(c) {}
};
template <class T>
bool operator<(const Edge<T> e1, const Edge<T> e2) {
    return e1.cost < e2.cost || (e1.cost == e2.cost && e1.from < e2.from) ||
           (e1.cost == e2.cost && e1.from == e2.from && e1.to < e2.to);
}

template <class T>
ostream &operator<<(ostream &os, const Edge<T> &edge) {
    os << "(" << edge.from << "->" << edge.to << ":" << edge.cost << ")";
    return os;
}

template <class T = int>
class Graph {
    int n;
    bool directed;
    vector<vector<Edge<T>>> edges;

  public:
    Graph(int n, bool directed)
        : n(n), directed(directed), edges(vector<vector<Edge<T>>>(n)) {}

    void add_edge(int s, int t, T cost) {
        edges[s].emplace_back(s, t, cost);
        if (!directed) {
            edges[t].emplace_back(t, s, cost);
        }
    }
    Graph() {}

    vector<Edge<T>> &operator[](size_t i) {
        return edges[i];
    }

    int size() const {
        return n;
    }
};

//======================================================

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

int main(void) {
    int N, M;
    cin >> N >> M;

    auto operation = [](ll a, ll b) { return max(a, b); };
    auto adapt_lazy = [](ll a, ll b) { return a + b; };
    auto merge_lazy = [](ll a, ll b) { return a + b; };
    auto multiply_lazy = [](ll a, int n) { return a; };
    LazySegTree<ll, ll> st(N + 1, 0, -INFL, 0, operation, adapt_lazy,
                           merge_lazy, multiply_lazy);

    vec<tuple<int, int, int>> lra(M), rla(M);
    rep(i, M) {
        int l, r, a;
        cin >> l >> r >> a;
        lra[i] = mt(l, r, a);
        rla[i] = mt(r, l, a);
    }
    sort(all(lra));
    sort(all(rla));

    ll ans = 0;
    int lra_idx = 0, rla_idx = 0;
    repr(i, 1, N + 1) {
        while (lra_idx < M && get<0>(lra[lra_idx]) == i) {
            // 追加
            st.range_operation(0, i, get<2>(lra[lra_idx]));
            lra_idx++;
        }
        ll val = st.query(0, i);
        chmax(ans, val);
        st.range_operation(i, i + 1, val);

        while (rla_idx < M && get<0>(rla[rla_idx]) == i) {
            // 削除
            st.range_operation(0, get<1>(rla[rla_idx]), -get<2>(rla[rla_idx]));
            rla_idx++;
        }
    }
    cout << ans << endl;

    return 0;
}
