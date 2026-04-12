#include <iostream>
#include <cstdio>
#include <vector>
#include <array>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <cassert>
#include <tuple>
#include <list>
#include <iterator>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <complex>

using namespace std;

typedef long long ll;
typedef long double ld;

template<class htpe, class cmp>
using heap = priority_queue<htpe, vector<htpe>, cmp>;

template<class htpe>
using min_heap = heap<htpe, greater<htpe> >;

template<class htpe>
using max_heap = heap<htpe, less<htpe> >;

#define mp make_pair
#define pb push_back
#define mt make_tuple
#define ff first
#define ss second

#define forn(i, n) for (int i = 0; i < ((int)(n)); ++i)
#define forrn(i, s, n) for (int i = (int)(s); i < ((int)(n)); ++i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define PYMOD(a, m) ((((a) % (m)) + (m)) % (m))

const int INF = 1791791791;
const ll INFLL = 1791791791791791791ll;
const int MOD = 1e9 + 7;

const int maxn = 100179;

struct digraph {
    vector<pair<int, int> > graph[maxn];
    ll dist[maxn];
    int numout[maxn];

    digraph() {}

    void dfs(int u) {
        for (auto p : graph[u]) {
            if (dist[p.ff] == -1) {
                dist[p.ff] = dist[u] + p.ss;
                dfs(p.ff);
            }
            numout[u] += numout[p.ff];
            numout[u] %= MOD;
        }
    }

    void calc(int s, int t) {
        memset(dist, 0xff, sizeof(dist));
        memset(numout, 0, sizeof(numout));
        dist[s] = 0;
        numout[t] = 1;
        dfs(s);
    }
};

int n;
digraph fwd, bckw;

vector<pair<int, int> > graph[maxn];
ll dijkstra(int s, int t, digraph& to_build) {
    vector<ll> dist(n, INFLL);
    vector<bool> used(n, false);
    priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > q;
    q.push(mp(0, s));
    dist[s] = 0;
    while (!used[t]) {
        auto p = q.top();
        q.pop();
        if (used[p.ss])
            continue;
        used[p.ss] = true;
        for (auto pp : graph[p.ss]) {
            if (!used[pp.ff]) {
                if (dist[pp.ff] > dist[p.ss] + pp.ss)
                    q.push(mp(dist[p.ss] + pp.ss, pp.ff));
                dist[pp.ff] = min(dist[pp.ff], dist[p.ss] + pp.ss);
            }
        }
    }

    forn(v, n) {
        for (auto p : graph[v]) {
            if (dist[p.ff] == dist[v] + p.ss)
                to_build.graph[v].pb(p);
        }
    }
    to_build.calc(s, t);
    return dist[t];
}

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    // Code here:

    int m;
    cin >> n >> m;
    int s, t;
    cin >> s >> t;
    s--; t--;
    forn(i, m) {
        int u, v, d;
        cin >> u >> v >> d;
        u--; v--;
        graph[u].pb(mp(v, d));
        graph[v].pb(mp(u, d));
    }

    ll dist = dijkstra(s, t, fwd);
    dijkstra(t, s, bckw);

    /*
    cout << dist << endl;
    cout << "fwd:" << endl;
    forn(i, n) {
        for (auto p : fwd.graph[i]) {
            cout << i << " " << p.ff << " " << p.ss << endl;
        }
    }
    forn(i, n)
        cout << i << " in: " << bckw.numout[i] << " out: " << fwd.numout[i] << " dist: " << fwd.dist[i] << endl;
    cout << "bckw:" << endl;
    forn(i, n) {
        for (auto p : bckw.graph[i]) {
            cout << i << " " << p.ff << " " << p.ss << endl;
        }
    }
    forn(i, n)
        cout << i << " in: " << fwd.numout[i] << " out: " << bckw.numout[i] << " dist: " << bckw.dist[i] << endl;
    */

    ll ans = 0;
    forn(i, n) {
        if (2 * fwd.dist[i] == dist) {
            ans += 1ll * PYMOD(fwd.numout[s] - 1ll * fwd.numout[i] * bckw.numout[i], MOD) * PYMOD(1ll * bckw.numout[i] * fwd.numout[i], MOD);
            ans %= MOD;
        }
    }

    forn(v, n) {
        for (auto p : fwd.graph[v]) {
            if (2 * fwd.dist[v] < dist && dist < 2 * fwd.dist[p.ff]) {
                ans += 1ll * PYMOD(fwd.numout[s] - 1ll * fwd.numout[p.ff] * bckw.numout[v], MOD) * PYMOD(1ll * bckw.numout[v] * fwd.numout[p.ff], MOD);
                ans %= MOD;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
