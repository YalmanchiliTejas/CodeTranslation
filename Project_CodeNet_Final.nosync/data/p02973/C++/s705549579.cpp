#include <bits/stdc++.h>
using namespace std;

// 変数ダンプ先。coutかcerr
#define DUMPOUT cerr

// 提出時はコメントアウト
#define DEBUG_

// #define int long long // intで書いたけど心配なときにlong longに変換する
struct Fast {Fast(){std::cin.tie(0);ios::sync_with_stdio(false);}} fast;

/* cpp template {{{ */

/* short */
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fi first
#define Se second
#define ALL(v) begin(v), end(v)
#define RALL(v) rbegin(v), rend(v)
#define X real()
#define Y imag()

/* REPmacro */
#define REPS(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define REP(i, n) REPS(i, 0, n)
#define RREP(i, n) REPS(i, 1, n + 1)
#define DEPS(i, a, n) for (ll i = (a); i >= (ll)(n); --i)
#define DEP(i, n) DEPS(i, n, 0)
#define EACH(i, n) for (auto&& i : n)

/* debug */
#define debug(x) cerr << x << " " << "(L:" << __LINE__ << ")" << '\n';

/* alias */
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using pii = pair<int, int>;
using D = double;
using P = complex<D>;
using vs = vector<string>;
template <typename T> using PQ = priority_queue<T>;
template <typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

/* const */
const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1e9 + 7;
const D EPS = 1e-9;
const int dx[] = {0, 1, 0, -1, 1, -1, 1, -1}, dy[] = {1, 0, -1, 0, 1, -1, -1, 1};

/* func */
inline bool inside(int y, int x, int H, int W) {return y >= 0 && x >= 0 && y < H && x < W;}
inline int in() {int x; cin >> x; return x;}
inline ll IN() {ll x; cin >> x; return x;}
inline vs split(const string& t, char c) {vs v; stringstream s(t); string b; while(getline(s, b, c)) v.eb(b); return v;}
template <typename T> inline bool chmin(T& a, const T& b) {if (a > b) a = b; return a > b;}
template <typename T> inline bool chmax(T& a, const T& b) {if (a < b) a = b; return a < b;}
template <typename T, typename S> inline void print(const pair<T, S>& p) {cout << p.first << " " << p.second << endl;}
template <typename T> inline void print(const T& x) {cout << x << '\n';}
template <typename T, typename S> inline void print(const vector<pair<T, S>>& v) {for (auto&& p : v) print(p);}
template <typename T> inline void print(const vector<T>& v, string s = " ") {REP(i, v.size()) cout << v[i] << (i != (ll)v.size() - 1 ? s : "\n");}
// clang-format on
/* }}} */

#ifdef DEBUG_
#define DEB
#else
// DEB と打つとデバッグ時以外はコメントアウトになる
#define DEB /##/
#endif

// 変数ダンプ用マクロ。デバッグ時以外は消滅する
// 引数はいくつでもどんな型でも可（ストリーム出力演算子があればOK）
#define dump(...) DEB DUMPOUT<<"  "; \
DUMPOUT<<#__VA_ARGS__<<" :["<<__LINE__<<":"<<__FUNCTION__<<"]"<<endl; \
DUMPOUT<<"    "; \
dump_func(__VA_ARGS__)

// デバッグ用変数ダンプ関数
void dump_func() {
    DUMPOUT << endl;
}
template <class Head, class... Tail>
void dump_func(Head&& head, Tail&&... tail)
{
    DUMPOUT << head;
    if (sizeof...(Tail) == 0) {
        DUMPOUT << " ";
    }
    else {
        DUMPOUT << ", ";
    }
    dump_func(std::move(tail)...);
}

// vector出力
template<typename T>
ostream& operator << (ostream& os, vector<T>& vec) {
    os << "{";
    for (int i = 0; i<vec.size(); i++) {
        os << vec[i] << (i + 1 == vec.size() ? "" : ", ");
    }
    os << "}";
    return os;
}

ll mod = 1000000007;

ll modplus(ll x, ll y) {
    return (x + y) % mod;
}

ll modminus(ll x, ll y) {
    return (x - y + mod) % mod;
}

ll multiply(ll x, ll y) {
    return (x % mod) * (y % mod) % mod;
}

ll power(ll x, ll y) {
    if (y == 0) {
        return 1;
    } else if (y == 1) {
        return x % mod;
    } else if (y % 2 == 0) {
        ll p = power(x, y / 2);
        return p * p % mod;
    } else {
        ll p = power (x, y / 2);
        return (p * p) % mod * (x % mod) % mod;
    }
}

ll divide(ll x, ll y) {
    return multiply(x, power(y, mod - 2));
}

ll frac[1000000];
ll invfrac[1000000];

void fracinvfrac(ll n) {
    frac[0] = 1;
    for (int i = 1; i <= n; i++) {
        frac[i] = multiply(frac[i - 1], i);
    }
    invfrac[n] = divide(1, frac[n]);
    for (int i = n - 1; i >= 0; i--) {
        invfrac[i] = multiply(invfrac[i + 1], i + 1);
    }
}

ll modcombi(ll x, ll y) {
    if (y == 0) {
        return 1;
    } else {
        return multiply(multiply(frac[x], invfrac[x - y]), invfrac[y]);
    }
}

vector<vector<int>> calcNext(vector<int> A) {
    int n = (int)A.size();
    vector<vector<int>> res(n+1, vector<int>(100001, n));
    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j < 100001; ++j) res[i][j] = res[i+1][j];
        res[i][A[i]] = i;
    }
    return res;
}

ll A[100000];

signed main() {
    // 昇順に処理する
    std::priority_queue<
    ll,                // 要素の型はint
    std::vector<ll>,   // 内部コンテナはstd::vector (デフォルトのまま)
    std::greater<ll>   // 昇順 (デフォルトはstd::less<T>)
    > que, q2;

    // while (!que.empty()) {
    // std::cout << que.top() << std::endl;
    // que.pop();
    // }

    ll N; cin >> N;
    REP(i, N) cin >> A[i];
    ll m;
    ll ans;
    m = A[0];
    ans = 1;
    // que.push(A[0]);
    // REPS(i, 1, N) {
    //     std::priority_queue<
    //     ll,                // 要素の型はint
    //     std::vector<ll>,   // 内部コンテナはstd::vector (デフォルトのまま)
    //     std::greater<ll>   // 昇順 (デフォルトはstd::less<T>)
    //     > empty;
    //     swap(empty, q2);
    //     m = que.top();
    //     if (A[i] <= m) {
    //         ans++;
    //         que.push(A[i]);
    //     } else {
    //         que.pop();
    //         que.push(A[i]);
    //     }
    //     while(!que.empty()) {
    //         q2.push(que.top());
    //         cout << que.top() << " ";
    //         que.pop();
    //     }
    //     cout << endl;
    //     swap(que, q2);
    // }

    vector<ll> v;
    v.pb(A[0]);
    m = v[0];
    ans = 1;
    REPS(i, 1, N) {
        m = v[0];
        if (A[i] <= m) {
            ans++;
            v.insert(v.begin(), A[i]);
        } else {
            auto Iter = lower_bound(ALL(v), A[i]);
            *(Iter-1) = A[i];
        }
    }

    print(ans);

    return 0;
}

// https://github.com/kurokoji/.cpp-Template/wiki テンプレートについて
// http://www.creativ.xyz/dump-cpp-652 dump()について
// https://gist.github.com/rigibun/7905920 色々