#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(),a.end()
#define pw(x) (1LL<<(x))

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl

using namespace std;

typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;
const int MOD = 1e9 + 7;




int main() {
#define TASK "A"
#ifdef HOME
    assert(freopen(TASK".in", "r", stdin));
#endif
    int n, m;
    scanf("%d%d", &n,  &m);
    int s, t;
    scanf("%d%d", &s, &t); s--; t--;
    vector<vector<pair<int,ll>>> e(n);
    for (int i = 0; i < m; i++) {
        int v, u, d;
        scanf("%d%d%d", &v, &u, &d); v--; u--;
        d *= 2;
        e[v].pb({u, d});
        e[u].pb({v, d});
    }

    auto dijkstra = [&](int st, vector<ll>& dist, vector<ll>& comb) {
        //db(st);
        dist.resize(n, 1e18);
        comb.resize(n);
        dist[st] = 0;
        comb[st] = 1;
        set<pair<ll,int>> q;
        q.insert({0, st});
        while (!q.empty()) {
            int v = q.begin()->S;
            q.erase(q.begin());
            for (auto x: e[v]) {
                int u = x.F;
                if (dist[u] > dist[v] + x.S) {
                    q.erase({dist[u], u});
                    dist[u] = dist[v] + x.S;
                    comb[u] = 0;
                    q.insert({dist[u], u});
                }
                if (dist[u] == dist[v] + x.S) {
                    comb[u] = (comb[u] + comb[v]) % MOD;
                }
            }
        }
    };

    vector<ll> distS, distT, combS, combT;
    dijkstra(s, distS, combS);
    dijkstra(t, distT, combT);

    ll len = distS[t];
//    db(len);
//    dbv(distS);
//    dbv(distT);
//    db2(distS[t], distT[s]);
    assert(len == distT[s]);
    assert(len % 2 == 0);

    vector<ll> meet;

    ll answer = 0;
    answer = combS[t] * combS[t] % MOD;
    auto sqr = [&](ll x) {
        return x * x % MOD;
    };

    for (int i = 0; i < n; i++) {
        if (distS[i] == distT[i] && distS[i] == len / 2)  {
            answer = (answer - sqr(combS[i] * combT[i] % MOD) + MOD) % MOD;
        }
        for (auto x: e[i]) {
            int u = x.F;
            if (distT[u] + x.S + distS[i] == len && distT[u] < len / 2 && distS[i] < len / 2) {
                //meet.pb(combS[i] * combT[u] % MOD);
                answer = (answer - sqr(combS[i] * combT[u] % MOD) + MOD) %  MOD;
            }
        }
    }
    ll sum = 0;
    for (auto x: meet) {
        sum = (sum + x) % MOD;
    }

    for (auto x: meet) {
        answer = (answer + x * (sum - x + MOD)) % MOD;
    }
    cout << answer << endl;
    return 0;
}
