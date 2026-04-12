#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <iomanip>
#include <numeric>
#include <tuple>
#include <bitset>
#include <complex>
#include <unistd.h>
#include <cassert>
#include <cctype>
#include <random>
#include <time.h>
#define _USE_MATH_DEFINES
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> plglg;
typedef pair<double, ll> pdlg;
typedef tuple<int, int, int> tiii;
typedef tuple<ll, ll, ll> tlglglg;
typedef tuple<double, double, double> tddd;
typedef complex<double> xy_t;
typedef vector<ll> vll;
typedef vector< vector<ll> > matrix;
#define REP(i, x, y) for(ll i = (ll)x; i < (ll)y; i++)
#define DREP(i, x, y, d) for(ll i = (ll)x; i < (ll)y; i += (ll)d)
#define PER(i, x, y) for(ll i = (ll)x; i > (ll)y; i--)
#define DPER(i, x, y, d) for(ll i = (ll)x; i > (ll)y; i -= (ll)d)
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
double pi = 3.141592653589793;
ll mod = 1000000007;
int intmax = 2147483647;
int intmin = -2147483648;
ll llmax = 9223372036854775807;
ll llmin = -9223372036854775807;
int iinf = intmax / 8;
ll inf = llmax / 8;
double eps = 1e-12;

ll modadd(ll x, ll y) {
    return ((x + y) % mod + mod) % mod;
}

ll modminus(ll x, ll y) {
    return (x - y + mod) % mod;
}

ll multiply(ll x, ll y) {
    return (x % mod) * (y % mod) % mod;
}

ll modpower(ll x, ll y) {
    if (y == 0) {
        return 1;
    } else if (y == 1) {
        return x % mod;
    } else if (y % 2 == 0) {
        ll p = modpower(x, y / 2);
        return p * p % mod;
    } else {
        ll p = modpower (x, y / 2);
        return (p * p) % mod * (x % mod) % mod;
    }
}

struct edge {
    ll to, cost;
};

int V;
vector<edge> G[100010];
ll d1[100010], d2[100010];
ll dp1[100010], dp2[100010];

void addedge(int st, int ed, ll co) {
    edge e;
    e.to = ed;
    e.cost = co;
    G[st].push_back(e);
}

void dijkstra(int s, ll* ary, ll* nowdp) {
    priority_queue<plglg, vector<plglg>, greater<plglg> > que;
    fill(ary, ary + V + 10, llmax);
    ary[s] = 0;
    nowdp[s] = 1;
    que.push(plglg(0, s));

    while (!que.empty()) {
        plglg p = que.top();
        que.pop();
        ll v = p.second;
        if (ary[v] < p.first) {
            continue;
        }
        int len = G[v].size();
        for (int i = 0; i < len; i++) {
            edge e = G[v][i];
            if (ary[e.to] > ary[v] + e.cost) {
                ary[e.to] = ary[v] + e.cost;
                nowdp[e.to] = nowdp[v];
                que.push(plglg(ary[e.to], e.to));
            } else if (ary[e.to] == ary[v] + e.cost) {
                nowdp[e.to] = modadd(nowdp[e.to], nowdp[v]);
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    V = N;
    ll S, T;
    cin >> S >> T;
    ll U[M], V[M], D[M];
    REP(i, 0, M) {
        cin >> U[i] >> V[i] >> D[i];
        addedge(U[i] - 1, V[i] - 1, D[i]);
        addedge(V[i] - 1, U[i] - 1, D[i]);
    }
    dijkstra(S - 1, d1, dp1);
    dijkstra(T - 1, d2, dp2);
    // REP(i, 0, N) {
    //     cout << d1[i] << " ";
    // }
    // cout << endl;
    // REP(i, 0, N) {
    //     cout << d2[i] << " ";
    // }
    // cout << endl;
    // cout << "aaa" << endl;
    // REP(i, 0, N) {
    //     cout << dp1[i] << " ";
    // }
    // cout << endl;
    // REP(i, 0, N) {
    //     cout << dp2[i] << " ";
    // }
    // cout << endl;
    ll ans = multiply(dp1[T - 1], dp2[S - 1]);
    REP(i, 0, N) {
        if (d1[i] == d2[i] && d1[i] + d2[i] == d1[T - 1]) {
            ans = modadd(ans, -multiply(multiply(dp1[i], dp2[i]), multiply(dp1[i], dp2[i])));
            // cout << i << endl;
        }
    }
    REP(i, 0, M) {
        ll p = U[i] - 1;
        ll q = V[i] - 1;
        if (d1[p] < d1[q]) {
            if (d1[q] == d1[p] + D[i] && d2[p] == d2[q] + D[i] && d1[p] + D[i] + d2[q] == d1[T - 1]) {
                if (d1[p] < d2[p] && d2[q] < d1[q]) {
                    ans = modadd(ans, -multiply(multiply(dp1[p], dp2[q]), multiply(dp1[p], dp2[q])));
                    // cout << p << " " << q << endl;
                    // cout << dp1[p] << " " << dp2[q] << endl;
                    // cout << "aaa" << endl;
                }
            }
        } else {
            if (d1[p] == d1[q] + D[i] && d2[q] == d2[p] + D[i] && d1[q] + D[i] + d2[p] == d1[T - 1]) {
                if (d1[q] < d2[q] && d2[p] < d1[p]) {
                    ans = modadd(ans, -multiply(multiply(dp1[q], dp2[p]),multiply(dp1[q], dp2[p])));
                    // cout << p << " " << q << endl;
                }
            }
        }
    }
    cout << ans << endl;
}
