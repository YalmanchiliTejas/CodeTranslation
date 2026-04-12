#include <bits/stdc++.h>
using namespace std;

#define rep(i, m, n) for(int(i) = (int)(m); i < (int)(n); ++i)
#define rep2(i, m, n) for(int(i) = (int)(n)-1; i >= (int)(m); --i)
#define REP(i, n) rep(i, 0, n)
#define REP2(i, n) rep2(i, 0, n)
#define all(hoge) (hoge).begin(), (hoge).end()
#define en '\n'
using ll = long long;
using ull = unsigned long long;
template <class T>
using vec = vector<T>;
template <class T>
using vvec = vector<vec<T>>;
typedef pair<ll, ll> P;
using tp = tuple<ll, ll, ll>;
constexpr long long INF = 1LL << 60;
constexpr int INF_INT = 1 << 25;
//constexpr long long MOD = (ll)1e9 + 7;
constexpr long long MOD = 998244353LL;
using ld = long double;
static const ld pi = 3.141592653589793L;
typedef vector<ll> Array;
typedef vector<Array> Matrix;

template <class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

//グラフ関連
struct Edge {
    ll to, cap, rev;
    Edge(ll _to, ll _cap, ll _rev) {
        to = _to;
        cap = _cap;
        rev = _rev;
    }
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void add_edge(Graph &G, ll from, ll to, ll cap, bool revFlag, ll revCap) {
    G[from].push_back(Edge(to, cap, (ll)G[to].size()));
    if(revFlag)
        G[to].push_back(Edge(from, revCap, (ll)G[from].size() - 1));
}

void solve() {
    ll n;
    cin >> n;
    vec<ll> a(3 * n);
    REP(i, 3 * n) {
        cin >> a[i];
    }

    vvec<ll> dp(n + 1, vec<ll>(n + 1, -1));
    vec<ll> mak(n + 1, -1);

    dp[a[0]][a[1]] = 0;
    dp[a[1]][a[0]] = 0;
    mak[a[0]] = 0;
    mak[a[1]] = 0;
    ll all = 0;
    ll ma = 0;
    REP(i, n - 1) {
        vec<tp> ndp;
        vec<ll> b({a[i * 3 + 2], a[i * 3 + 3], a[i * 3 + 4]});
        if(b[0] == b[1] and b[1] == b[2]) {
            all++;
            continue;
        }

        REP(j, 3) {
            //どれか二つを使う
            if(b[(j + 1) % 3] == b[(j + 2) % 3]) {
                rep(k, 1, n + 1) {
                    if(dp[b[(j + 1) % 3]][k] == -1)
                        continue;
                    ndp.push_back({b[j], (ll)k, dp[b[(j + 1) % 3]][k] + 1});
                }
            }

            //どれか一つだけ使う
            if(dp[b[j]][b[j]] != -1)
                ndp.push_back({b[(j + 1) % 3], b[(j + 2) % 3], dp[b[j]][b[j]] + 1});

            //どれか一つだけすてる
            ndp.push_back({b[(j + 1) % 3], b[(j + 2) % 3], ma});

            //どれか二つをすてる
            rep(k, 1, n + 1) {
                if(mak[k] == -1)
                    continue;
                ndp.push_back({b[j], (ll)k, mak[k]});
            }
        }
        for(auto [x, y, num] : ndp) {
            chmax(ma, num);
            chmax(mak[x], num);
            chmax(mak[y], num);
            chmax(dp[x][y], num);
            chmax(dp[y][x], num);
        }
    }
    chmax(ma, dp[a[3 * n - 1]][a[3 * n - 1]] + 1);
    cout << ma + all << en;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    /*
    ll t;
    cin >> t;
    while(t--)*/
    solve();

    return 0;
}
