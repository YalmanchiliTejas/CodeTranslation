#include <iostream>
#include <iomanip>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>
#include <cassert>
#include <fstream>
#include <algorithm>
#include <list>
#include <random>
#include <ctime>
#include <cmath>
#include <random>
#include <bitset>
#include <complex>
#pragma unroll
#pragma loop count N
#pragma ivdep
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define int ll
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;
typedef vector<short> vs;
typedef vector<vs> vvs;
typedef vector<vvs> vvvs;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef pair<ld, ld> pld;
typedef complex<double> base;

#define mmin(a, b) a = min(a, (b))
#define mmax(a, b) a = max(a, (b))
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define ALL(a) a.begin(),a.end()
#define sqr(x) (x) * (x)
#define fori(i, n) for(int i = 0; i < int(n); ++i)
#define cint const int &
#define SZ(a) ((int)(a.size()))
#define f(cnt) (((cnt) + 1) * (cnt) / 2)
#define watch(x) cout << (#x) << " = " << x << endl;

const double PI = 2 * acos(0.0);

template<class T>
void show(const set<T> &a) {
    for (T x : a)
        cout << x << " ";
    cout << endl;
}

template<class T>
void show(const vector<T> &a) {
    for (T x : a)
        cout << x << " ";
    cout << endl;
}

const ll M = 1e9 + 7;

ll MOD(ll a) {
    if (a >= 0) return a >= M ? a % M : a;
    if (a <= -M) a %= M;
    return a ? a + M : a;
}

const int N = 109;
const int L = 1e6 + 7;

struct edge {
    int u, v;
    ll height;
    edge(int u, int v, ll height): u(u), v(v), height(height) {

    }

};
vector<edge> e;

ll pw(ll a, ll p) {
    if (p < 0LL) return pw(pw(a, -p), M - 2);
    if (!p) return 1;
    ll ret = pw(a, p >> 1LL);
    ret = MOD(ret * ret);
    if (p & 1LL) ret = MOD(ret * a);
    return ret;
}

int counter = 1;
vi g[L];
ll len[L];
int vert[L];
int start[L];
ll h[N];
ll dp[2][L];

inline ll get_ways(int v) {
    vvvl dp(N, vvl(2, vl(2, 0)));
    vector<char> must(N, 0);
    for (int id : g[v]) {
        int to = e[id].v;
        for (int i = 1; i < len[to]; ++i)
            must[i + start[to]] = 1;
    }
    dp[start[v]][0][0] = dp[start[v]][0][1] = 1;
    for (int i = 1; i < len[v]; ++i) {
        int ind = i + start[v];
        if (must[ind]) {
            for (int z1 : {0, 1}) for (int z2 : {0, 1})
                dp[ind][z1][z2] = dp[ind - 1][z1][!z2];
        } else {
            for (int z1 : {0, 1}) for (int z2 : {0, 1}) for (int z3 : {0, 1}) {
                int nx = z1;
                if (z2 != z3) nx = 1;
                dp[ind][nx][z3] = MOD(dp[ind][nx][z3] + dp[ind - 1][z1][z2]);
            }
        }
    }
    ll ret = MOD(dp[start[v] + len[v] - 1][1][0] + dp[start[v] + len[v] - 1][1][1]);
    return ret;
}

ll dfs(int v) {
    ll dp0 = 1;
    ll dp1 = 1;
    ll dp2 = 0;
    ll restlen = len[v];
    for (int id : g[v]) {
        int to = e[id].v;
        dfs(to);
        restlen -= len[to];
        ll curgood = MOD(pw(2, e[id].height - 1) * dp[0][to]);
        ll curbad = dp[1][to];
        dp2 = MOD(dp2 * (curgood * 2 + curbad) + dp1 * curbad);
        dp1 = MOD(dp1 * curgood * 2);
        dp0 = MOD(dp0 * curgood);
    }
    dp[1][v] = MOD(dp2 * pw(2, restlen) + dp0 * get_ways(v));
    dp[0][v] = MOD(2 * dp0);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    set<ll> hs;
    fori (i, n) {
        cin >> h[i];
        hs.insert(h[i]);
    }
    if (n == 1) {
        cout << pw(2, h[0]);
        return 0;
    }
    ll prev = 0;
    len[counter++] = n;
    fori (i , n)
        vert[i] = 1;
    int curv = 0;
    int par = 0;
    for (auto hi : hs) {
        int cnt = 0;
        fori (i, n) {
            if (h[i] >= hi) {
                if (!cnt) {
                    curv = counter++;
                    start[curv] = i;
                    par = vert[i];
                }
                vert[i] = curv;
                cnt++;
            } else {
                if (cnt >= 2) {
                    len[curv] = cnt;
                    g[par].pb(SZ(e));
                    e.pb(edge(par, curv, hi - prev));
                }
                cnt = 0;
            }
        }
        if (cnt >= 2) {
            len[curv] = cnt;
            g[par].pb(SZ(e));
            e.pb(edge(par, curv, hi - prev));
        }
        prev = hi;
    }
    ll fre = 0;
    fori (i, n) {
        ll neib = 0;
        if (i) mmax(neib, h[i - 1]);
        if (i != n - 1) mmax(neib, h[i + 1]);
        fre += max(0LL, h[i] - neib);
    }
    int id = g[1][0];
    int vertex = e[id].v;
    dfs(vertex);
    ll ans = MOD(dp[0][vertex] * pw(2, e[id].height - 1) + dp[1][vertex]);
    ans = MOD(ans * pw(2, fre));
    cout << ans;
}