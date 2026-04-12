#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric>
#include <queue>
#include <stack>
#include <map> 
#include <set>
#include <string>
#include <functional>
#include <list>
#include <random>
#include <time.h>
#include <iomanip>
#include <assert.h>
#include <numeric>
#define int long long
//#define ll long long
#define double long double
#define mod 1000000007
#define MAXN (int)1e+5 * 2+1
#define LL_MAX 9223372036854775807	//ない環境用
#define LL_HALFMAX 9223372036854775807 / 2	//ない環境用
#define MIN -(9223372036854775807 / 2)
#define INF 9223372036854775807 / 2
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define mp make_pair
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b) { if (a>b) a = b; }
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b) { if (a<b) a = b; }


using namespace std;

std::mt19937 mt((int)time(0));

int dx[4] = { 0, 1, 0, -1 }; // x軸方向への変位
int dy[4] = { 1, 0, -1, 0 }; // y軸方向への変位

using Weight = int;
using Flow = int;
struct Edge {
    int src, dst;
    Weight weight;
    Flow cap;
    Edge() : src(0), dst(0), weight(0) {}
    Edge(int s, int d, Weight w) : src(s), dst(d), weight(w) {}
};
using Edges = std::vector<Edge>;
using Graph = std::vector<Edges>;
using Array = std::vector<Weight>;
using Matrix = std::vector<Array>;

void add_edge(Graph &g, int a, int b, Weight w = 1) {
    g[a].emplace_back(a, b, w);
    g[b].emplace_back(b, a, w);
}
void add_arc(Graph &g, int a, int b, Weight w = 1) { g[a].emplace_back(a, b, w); }

struct uf_tree {
    std::vector<int> parent;
    int __size;
    uf_tree(int size_) : parent(size_, -1), __size(size_) {}
    void unite(int x, int y) {
        if ((x = find(x)) != (y = find(y))) {
            if (parent[y] < parent[x]) std::swap(x, y);
            parent[x] += parent[y];
            parent[y] = x;
            __size--;
        }
    }
    bool is_same(int x, int y) { return find(x) == find(y); }
    int find(int x) { return parent[x] < 0 ? x : parent[x] = find(parent[x]); }
    int size(int x) { return -parent[find(x)]; }
    int size() { return __size; }
};



//!!!問題をちゃんと読む!!!
//!!!問題をちゃんと読め!!!
//!!!問題は読みましたか？!!!

template <signed M, unsigned T>
struct mod_int {
    constexpr static signed MODULO = M;
    constexpr static unsigned TABLE_SIZE = T;

    signed x;

    mod_int() : x(0) {}

    mod_int(long long y) : x(static_cast<signed>(y >= 0 ? y % MODULO : MODULO - (-y) % MODULO)) {}

    mod_int(signed y) : x(y >= 0 ? y % MODULO : MODULO - (-y) % MODULO) {}

    mod_int &operator+=(const mod_int &rhs) {
        if ((x += rhs.x) >= MODULO) x -= MODULO;
        return *this;
    }

    mod_int &operator-=(const mod_int &rhs) {
        if ((x += MODULO - rhs.x) >= MODULO) x -= MODULO;
        return *this;
    }

    mod_int &operator*=(const mod_int &rhs) {
        x = static_cast<signed>(1LL * x * rhs.x % MODULO);
        return *this;
    }

    mod_int &operator/=(const mod_int &rhs) {
        x = static_cast<signed>((1LL * x * rhs.inv().x) % MODULO);
        return *this;
    }

    mod_int operator-() const { return mod_int(-x); }

    mod_int operator+(const mod_int &rhs) const { return mod_int(*this) += rhs; }

    mod_int operator-(const mod_int &rhs) const { return mod_int(*this) -= rhs; }

    mod_int operator*(const mod_int &rhs) const { return mod_int(*this) *= rhs; }

    mod_int operator/(const mod_int &rhs) const { return mod_int(*this) /= rhs; }

    bool operator<(const mod_int &rhs) const { return x < rhs.x; }

    mod_int inv() const {
        assert(x != 0);
        if (x <= static_cast<signed>(TABLE_SIZE)) {
            if (_inv[1].x == 0) prepare();
            return _inv[x];
        }
        else {
            signed a = x, b = MODULO, u = 1, v = 0, t;
            while (b) {
                t = a / b;
                a -= t * b;
                std::swap(a, b);
                u -= t * v;
                std::swap(u, v);
            }
            return mod_int(u);
        }
    }

    mod_int pow(long long t) const {
        assert(!(x == 0 && t == 0));
        mod_int e = *this, res = mod_int(1);
        for (; t; e *= e, t >>= 1)
            if (t & 1) res *= e;
        return res;
    }

    mod_int fact() {
        if (_fact[0].x == 0) prepare();
        return _fact[x];
    }

    mod_int inv_fact() {
        if (_fact[0].x == 0) prepare();
        return _inv_fact[x];
    }

    mod_int choose(mod_int y) {
        assert(y.x <= x);
        return this->fact() * y.inv_fact() * mod_int(x - y.x).inv_fact();
    }

    static mod_int _inv[TABLE_SIZE + 1];

    static mod_int _fact[TABLE_SIZE + 1];

    static mod_int _inv_fact[TABLE_SIZE + 1];

    static void prepare() {
        _inv[1] = 1;
        for (int i = 2; i <= (int)TABLE_SIZE; ++i) {
            _inv[i] = 1LL * _inv[MODULO % i].x * (MODULO - MODULO / i) % MODULO;
        }
        _fact[0] = 1;
        for (unsigned i = 1; i <= TABLE_SIZE; ++i) {
            _fact[i] = _fact[i - 1] * signed(i);
        }
        _inv_fact[TABLE_SIZE] = _fact[TABLE_SIZE].inv();
        for (int i = (int)TABLE_SIZE - 1; i >= 0; --i) {
            _inv_fact[i] = _inv_fact[i + 1] * (i + 1);
        }
    }
};

template <signed M, unsigned F>
std::ostream &operator<<(std::ostream &os, const mod_int<M, F> &rhs) {
    return os << rhs.x;
}

template <signed M, unsigned F>
std::istream &operator >> (std::istream &is, mod_int<M, F> &rhs) {
    long long s;
    is >> s;
    rhs = mod_int<M, F>(s);
    return is;
}

template <signed M, unsigned F>
mod_int<M, F> mod_int<M, F>::_inv[TABLE_SIZE + 1];

template <signed M, unsigned F>
mod_int<M, F> mod_int<M, F>::_fact[TABLE_SIZE + 1];

template <signed M, unsigned F>
mod_int<M, F> mod_int<M, F>::_inv_fact[TABLE_SIZE + 1];

template <signed M, unsigned F>
bool operator==(const mod_int<M, F> &lhs, const mod_int<M, F> &rhs) {
    return lhs.x == rhs.x;
}

template <int M, unsigned F>
bool operator!=(const mod_int<M, F> &lhs, const mod_int<M, F> &rhs) {
    return !(lhs == rhs);
}

const signed MF = 1000010;
const signed MOD = 1000000007;

using mint = mod_int<MOD, MF>;

mint binom(int n, int r) { return (r < 0 || r > n || n < 0) ? 0 : mint(n).choose(r); }

mint fact(int n) { return mint(n).fact(); }

mint inv_fact(int n) { return mint(n).inv_fact(); }

//出典 http://beet-aizu.hatenablog.com/entry/2017/12/01/225955
/*
コンストラクタ引数説明
int n_
要素数。
f
2つの要素Tをマージするための関数。
区間MAX区間更新の時: max
区間Sum区間Addの時: +
g
1つの要素Tに作用素Eを適用するための関数。
区間MAX区間更新の時: =
区間Sum区間Addの時: +
h
2つの作用素Eをマージするための関数。
区間MAX区間更新の時: =
区間Sum区間Addの時: +
T d1
演算fの単位元。
区間MAX区間更新の時: -INF　
区間Sum区間Addの時: 0
E d0,
g, hの単位元。
区間MAX区間更新の時: 定義域外のどこか
区間Sum区間Addの時: 0
vector<T> v = vector<T>()
セグ木を構成するときのvector
P p = [](E a, int b) {return a; }
区間の長さbを引数に取り、区間の長さによって変化する作用素E'を返す関数。
例えば、区間MAX区間Addの時なんかは区間長によって足すべき数が変化するので必要
区間Sum区間Addの時: *

//具体例
//区間chmin, 区間min
auto myMin = [](int a, int b) {return min(a, b); };
SegmentTree<int, int> seg(n, myMin, myMin, myMin, LL_HALFMAX, LL_HALFMAX);
//区間update、区間min
SegmentTree<int, int> seg(n, myMin, myMin, myMin, LL_HALFMAX, LL_HALFMAX);
*/

template <typename T, typename E>
struct SegmentTree {
    typedef function<T(T, T)> F;
    typedef function<T(T, E)> G;
    typedef function<E(E, E)> H;
    typedef function<E(E, int)> P;
    int n;
    F f;
    G g;
    H h;
    P p;
    T d1;
    E d0;
    vector<T> dat;
    vector<E> laz;
    SegmentTree(int n_, F f, G g, H h, T d1, E d0,
        vector<T> v = vector<T>(), P p = [](E a, int b) {return a; }) :
        f(f), g(g), h(h), d1(d1), d0(d0), p(p) {
        init(n_);
        if (n_ == (int)v.size()) build(n_, v);
    }
    //初期化。要素配列と遅延配列を2*n-1個にする
    void init(int n_) {
        n = 1;
        while (n<n_) n *= 2;
        dat.clear();
        dat.resize(2 * n - 1, d1);
        laz.clear();
        laz.resize(2 * n - 1, d0);
    }
    //既存のvectorからセグ木を構築
    void build(int n_, vector<T> v) {
        for (int i = 0; i<n_; i++) dat[i + n - 1] = v[i];
        for (int i = n - 2; i >= 0; i--)
            dat[i] = f(dat[i * 2 + 1], dat[i * 2 + 2]);
    }
    //ノードを評価する。
    inline void eval(int len, int k) {
        //遅延配列に単位元が入ってたら評価済みなのでおしまい
        if (laz[k] == d0) return;
        //葉ノードでないなら遅延伝播する
        if (k * 2 + 1<n * 2 - 1) {
            //h: 2つの作用素を引数に取り合成した作用素を返す関数
            laz[k * 2 + 1] = h(laz[k * 2 + 1], laz[k]);
            laz[k * 2 + 2] = h(laz[k * 2 + 2], laz[k]);
        }
        //p: このノードに対応する区間長と作用素を引数に取り、区間長に対応する作用素を返す関数
        //dat[k] にlaz に溜めていた作用素を適用(g: 要素型と作用素型を引数に取り、要素に作用素を作用させた結果を返す関数、ここでの作用素とは区間Sum区間Addなら (+ 3) とか)
        dat[k] = g(dat[k], p(laz[k], len));
        //適用し終わったので遅延配列をクリア
        laz[k] = d0;
    }
    //[l,r)の区間を再帰的に見ながら0-indexedの[a, b)を更新する
    T update(int a, int b, E x, int k, int l, int r) {
        //先に評価
        eval(r - l, k);
        //範囲外ならなにもしないでそのノードが持つ値を返す
        if (r <= a || b <= l) return dat[k];
        //完全被覆なら既に遅延配列に入っている作用素と追加したい作用素をマージした後にそれを要素に作用させた結果を返す、pは区間長に対応する作用素を得るための（ｒｙ
        if (a <= l && r <= b) {
            laz[k] = h(laz[k], x);
            return g(dat[k], p(laz[k], r - l));
        }
        //完全被覆でも範囲外でもないなら(中途半端にかぶっているなら)完全被覆と範囲外の境界が見えるまで木を潜って変化後の値を得る
        return dat[k] = f(update(a, b, x, k * 2 + 1, l, (l + r) / 2),
            update(a, b, x, k * 2 + 2, (l + r) / 2, r));
    }
    T update(int a, int b, E x) {
        return update(a, b, x, 0, 0, n);
    }
    //a だけ更新(点更新)
    T update(int a, E x) {
        return update(a, a + 1, x, 0, 0, n);
    }
    T query(int a, int b, int k, int l, int r) {
        eval(r - l, k);
        //範囲外なら単位元を返す
        if (r <= a || b <= l) return d1;
        //完全被覆ならそのまま返す
        if (a <= l && r <= b) return dat[k];
        //一部被覆なら完全被覆と範囲外に分かれるまで木を潜る
        T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return f(vl, vr);
    }
    //0-indexedで[a, b)の区間*を求める
    T query(int a, int b) {
        return query(a, b, 0, 0, n);
    }
    //点取得
    T query(int a) {
        return query(a, a + 1, 0, 0, n);
    }
};

//座標圧縮

class compress {
public:
    static const int MAP = 10000000;
    map<int, int> zip;
    int unzip[MAP];

    compress(vector<int> &x) {
        sort(x.begin(), x.end());
        x.erase(unique(x.begin(), x.end()), x.end());
        for (int i = 0; i < x.size(); i++) {
            zip[x[i]] = i;
            unzip[i] = x[i];
        }
    }
};


unsigned euclidean_gcd(unsigned a, unsigned b) {
    while (1) {
        if (a < b) swap(a, b);
        if (!b) break;
        a %= b;
    }
    return a;
}

//https://ei1333.github.io/luzhiled/snippets/dp/cumulative-sum-2d.html
template< class T >
struct CumulativeSum2D {
    vector< vector< T > > data;

    CumulativeSum2D(int W, int H) : data(W + 1, vector< int >(H + 1, 0)) {}

    void add(int x, int y, T z) {
        ++x, ++y;
        if (x >= data.size() || y >= data[0].size()) return;
        data[x][y] += z;
    }

    void build() {
        for (int i = 1; i < data.size(); i++) {
            for (int j = 1; j < data[i].size(); j++) {
                data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];
            }
        }
    }

    T query(int sx, int sy, int gx, int gy) {
        return (data[gx][gy] - data[sx][gy] - data[gx][sy] + data[sx][sy]);
    }
};

//lib
int nC2(int n) {
    return n * (n - 1) / 2;
}

class node {
public:
    int depth;
    int num;

    node(int d, int n) {
        depth = d;
        num = n;
    }
};

CumulativeSum2D<int> sumB(4001, 4001);

template< class T >
struct CumulativeSum {
    vector< T > data;

    CumulativeSum(int sz) : data(sz, 0) {};

    void add(int k, T x) {
        data[k] += x;
    }

    void build() {
        for (int i = 1; i < data.size(); i++) {
            data[i] += data[i - 1];
        }
    }

    T query(int k) {
        if (k < 0) return (0);
        return (data[min(k, (int)data.size() - 1)]);
    }
    //[left, right]の和
    T query(int left, int right) {
        return query(right) - query(left - 1);
    }
};

std::vector<bool> IsPrime;

void sieve(size_t max) {
    if (max + 1 > IsPrime.size()) {     // resizeで要素数が減らないように
        IsPrime.resize(max + 1, true); // IsPrimeに必要な要素数を確保
    }
    IsPrime[0] = false; // 0は素数ではない
    IsPrime[1] = false; // 1は素数ではない

    for (size_t i = 2; i*i <= max; ++i) // 0からsqrt(max)まで調べる
        if (IsPrime[i]) // iが素数ならば
            for (size_t j = 2; i*j <= max; ++j) // (max以下の)iの倍数は
                IsPrime[i*j] = false;      // 素数ではない
}

vector< int64_t > divisor(int64_t n) {
    vector< int64_t > ret;
    for (int64_t i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return (ret);
}

int N, K;
vector<int> A;

// k が条件を満たすかどうか
bool isOK(int k) {
    vector<int> moded(N);
    rep(i, N) {
        moded[i] = A[i] % k;
    }
    int su = 0;
    int su2 = 0;
    rep(i, N) {
        su += min(moded[i], abs(moded[i] - k));
        su2 += moded[i];

    }
    if (su <= K && su2 % k == 0) {
        return true;
    }


    return false;
}

// 汎用的な二分探索のテンプレ(めぐる式)
int binary_search() {
    int ng = 2000000;
    int ok = 1;

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (isOK(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}

class ExDijkstraNode {
public:
    int nowDist;
    int parity;
    int nowNode;
    ExDijkstraNode(int d, int p, int n) {
        nowDist = d;
        parity = p;
        nowNode = n;
    }
    bool operator<(const ExDijkstraNode &r) const {
        return nowDist < r.nowDist;
    }

    bool operator>(const ExDijkstraNode &r) const {
        return nowDist > r.nowDist;
    }
};

//型T の値Nについて、繰り返し二乗法でN^Pを計算する関数テンプレート
//http://satanic0258.hatenablog.com/entry/2016/04/29/004730
template <typename T>
T RepeatSquaring(T N, int P, function<T(T, T)> mul, T id) {
    if (P == 0) return id;
    if (P % 2 == 0) {
        T t = RepeatSquaring(N, P / 2, mul, id);
        return mul(t, t);
    }
    return mul(N, RepeatSquaring(N, P - 1, mul, id));
}

//行列積 a.b
vector<vector<mint>> dot(vector<vector<mint>> a, vector<vector<mint>>b) {
    vector<vector<mint>> ret;
    rep(i, a.size()) {
        vector<mint> v(b[0].size(), mint(0));
        ret.push_back(v);
    }

    rep(i, a.size()) {
        rep(j, b[0].size()) {
            rep(k, a.size()) {
                ret[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return ret;
}

mint dp[10001][101][2];
const int smaller = 1;
const int notSmaller = 0;

signed main() {
    string K;
    int D;
    cin >> K >> D;
    
    //dp[i][j][smaller] := i番目まで条件smallerを満たして決めたときあまりjになる場合の数
    int first = K[0] - '0';
    rep(i, first) {
        dp[0][i % D][smaller]+= mint(1);
    }
    dp[0][first % D][notSmaller] += mint(1);
    for(int i = 1;i<K.length(); i++) {
        int digi = K[i] - '0';
        //smaller->smaller(なんでもいい)、i桁目をjにすることを考える
        rep(j, 10) {
            //前のけたの和のmod + 今のけた のmod
            rep(k, D) {
                dp[i][(k + j) % D][smaller] += dp[i - 1][k][smaller];
            }
        }
        //notSmaller->smaller(digi 未満のみOK)
        rep(j, digi) {
            rep(k, D) {
                dp[i][(k + j) % D][smaller] += dp[i - 1][k][notSmaller];
            }
        }
        //notSmaller->notSmaller(digi のみOK)
        rep(k, D) {
            dp[i][(k + digi) % D][notSmaller] += dp[i - 1][k][notSmaller];
        }
    }
    //全部ゼロは除くので-1
    cout << dp[K.length() - 1][0][0] + dp[K.length() - 1][0][1] - 1 << "\n";

    return 0;
}
