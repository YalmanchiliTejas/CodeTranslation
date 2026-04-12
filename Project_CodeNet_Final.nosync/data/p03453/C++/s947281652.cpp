#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <numeric>
#include <cmath>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <complex>
#include <string.h>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <iomanip>
#include <sys/time.h>
#include <tuple>
#include <random>
using namespace std;

#define endl '\n'
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define UNIQ(v) (v).erase(unique((v).begin(), (v).end()), (v).end())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef complex<double> comp;
typedef vector< vector<ld> > matrix;
struct pairhash {
public:
    template<typename T, typename U>
    size_t operator()(const pair<T, U> &x) const {
        size_t seed = hash<T>()(x.first);
        return hash<U>()(x.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }
};
const int inf = 1e9 + 9;
const ll mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1);

int n, m;
int S, T;
int u[200100], v[200100];
ll d[200100];

const int MAX = 100100;
struct edge {
    int to;
    ll cost;
};

vector<edge> G[MAX];
ll D[2][MAX];
ll num[2][MAX];

void dijkstra(int s, int b) {
    priority_queue<P, vector<P>, greater<P> > que;
    for (int i = 0; i < MAX; i++) D[b][i] = 1e16;
    D[b][s] = 0;
    que.push(P(0, s));
    while (!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if (D[b][v] < p.first) continue;
        for (int i = 0; i < G[v].size(); i++) {
            edge e = G[v][i];
            if (D[b][e.to] > D[b][v] + e.cost) {
                D[b][e.to] = D[b][v] + e.cost;
                que.push(P(D[b][e.to], e.to));
            }
        }
    }
}


ll solve() {
    for (int i = 0; i < m; i++) {
        G[u[i]].push_back(edge{v[i], d[i]});
        G[v[i]].push_back(edge{u[i], d[i]});
    }
    dijkstra(S, 0);
    dijkstra(T, 1);
    vector<int> idx(n);
    for (int i = 0; i < n; i++) {
        idx[i] = i+1;
    }
    for (int k = 0; k < 2; k++) {
        sort(ALL(idx), [k](const int a, const int b){ return D[k][a] < D[k][b]; });
        for (int i = 0; i < n; i++) {
            int p = idx[i];
            if (i == 0) {
                num[k][p] = 1;
            }
            for (int j = 0; j < (int)G[p].size(); j++) {
                edge e = G[p][j];
                if (D[k][p] + e.cost == D[k][e.to]) num[k][e.to] = (num[k][e.to] + num[k][p]) % mod;
            }
        }
    }
    /*
     for (int i = 1; i <= n; i++) {
     cerr << num[0][i] << " ";
     }
     cerr << endl;
     for (int i = 1; i <= n; i++) {
     cerr << num[1][i] << " ";
     }
     cerr << endl;
     */
    ll minD = D[0][T];
    vector<ll> vec;
    if (minD % 2 == 0) {
        for (int i = 1; i <= n; i++) {
            if (D[0][i] == minD/2 && D[1][i] == minD/2) {
                vec.push_back((num[0][i] * num[1][i]) % mod);
            }
        }
    }
    for (int i = 0; i < m; i++) {
        if (minD % 2 == 1) {
            if (D[0][u[i]] + D[1][v[i]] + d[i] == minD && D[0][u[i]] <= minD/2 && D[1][v[i]] <= minD/2) vec.push_back((num[0][u[i]] * num[1][v[i]]) % mod);
            if (D[0][v[i]] + D[1][u[i]] + d[i] == minD && D[0][v[i]] <= minD/2 && D[1][u[i]] <= minD/2) vec.push_back((num[0][v[i]] * num[1][u[i]]) % mod);
        } else {
            if (D[0][u[i]] + D[1][v[i]] + d[i] == minD && D[0][u[i]] < minD/2 && D[1][v[i]] < minD/2) vec.push_back((num[0][u[i]] * num[1][v[i]]) % mod);
            if (D[0][v[i]] + D[1][u[i]] + d[i] == minD && D[0][v[i]] < minD/2 && D[1][u[i]] < minD/2) vec.push_back((num[0][v[i]] * num[1][u[i]]) % mod);
        }
    }
    
    ll sum = 0;
    int sz = (int)vec.size();
    for (int i = 0; i < sz; i++) {
        sum = (sum + vec[i]) % mod;
    }
    
    ll res = 0;
    for (int i = 0; i < sz; i++) {
        res = (res + vec[i] * ((sum - vec[i] + mod) % mod)) % mod;
    }
    return res;
}

void input() {
    cin >> n >> m;
    cin >> S >> T;
    for (int i = 0; i < m; i++) {
        cin >> u[i] >> v[i] >> d[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);
    
    input();
    cout << solve() << endl;
}
