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

struct unionFind {
    vector<int> data;
    unionFind(int size) : data(size, -1) {}
    
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x != y) {
            if(data[y] < data[x]) {
                swap(x, y);
            }
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    int root(int x) {
        return (data[x] < 0) ? x : data[x] = root(data[x]);
    }

    int rank(int x) {
        return -data[root(x)];
    }
};

//cost,from,toの順
vector<tlglglg> T;
vector<tlglglg> Krusans;

ll Kruskal(int n) {
    sort(T.begin(), T.end());
    ll ans = 0;
    ll num = 0;
    unionFind u(n);
    int size = T.size();
    for (int i = 0; i < size; i++) {
        ll cost = get<0>(T[i]);
        ll from = get<1>(T[i]);
        ll to = get<2>(T[i]);
        if (!u.same(from, to)) {
            u.unite(from, to);
            ans += cost;
            num++;
            tlglglg t = make_tuple(cost, from, to);
            Krusans.push_back(t);
        }
        if (num == n - 1) {
            break;
        }
    }
    if (num == n - 1) {
        return ans;
    } else {
        return llmax;
    }
}

struct edge {
    ll to, cost;
};

int V;
vector<edge> G[1000000];
ll d[1000000];

void addedge(int st, int ed, ll co) {
    edge e;
    e.to = ed;
    e.cost = co;
    G[st].push_back(e);
}

ll dif[4010][4010];

void dfs(int n) {
    fill(dif[n], dif[n] + V, -1);
    dif[n][n] = 0;
    queue<ll> que;
    que.push(n);
    while(!que.empty()) {
        ll q = que.front();
        que.pop();
        REP(i, 0, G[q].size()) {
            edge e = G[q][i];
            if (dif[n][e.to] != -1) {
                continue;
            }
            dif[n][e.to] = max(dif[n][q], e.cost);
            que.push(e.to);
        }
    }
}

int main() {
    ll N, M;
    cin >> N >> M;
    REP(i, 0, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        tlglglg t = tlglglg(c, a - 1, b - 1);
        T.push_back(t);
    }
    ll sum = Kruskal(N);
    V = N;
    REP(i, 0, N - 1) {
        tlglglg t = Krusans[i];
        addedge(get<1>(t), get<2>(t), get<0>(t));
        addedge(get<2>(t), get<1>(t), get<0>(t));
    }
    REP(i, 0, N) {
        dfs(i);
    }
    // REP(i, 0, N) {
    //     REP(j, 0, N) {
    //         cout << dif[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    ll Q;
    cin >> Q;
    REP(i, 0, Q) {
        ll s, t;
        cin >> s >> t;
        cout << sum - dif[s - 1][t - 1] << endl;
    }
}
