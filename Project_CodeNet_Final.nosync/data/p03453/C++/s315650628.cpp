#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

const double EPS = 1e-10;
const ll INF = 1000000000000000000;
const ll MOD = 1000000007;

ll n, m;
ll s, t;
vector<P> e[100000];
ll dist[2][100000];
ll cnt[2][100000];
bool ali[100000];

void dijk(int i, ll st) {
    rep(j,n) dist[i][j] = INF;
    rep(j,n) cnt[i][j] = 0;
    dist[i][st] = 0;
    cnt[i][st] = 1;
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0, st));
    while (!que.empty()) {
        P p = que.top();
        que.pop();
        if (dist[i][p.second] < p.first) continue;
        rep(j,e[p.second].size()) {
            if (dist[i][e[p.second][j].first] == p.first + e[p.second][j].second) {
                cnt[i][e[p.second][j].first] = (cnt[i][e[p.second][j].first]+cnt[i][p.second])%MOD;
            } else if (dist[i][e[p.second][j].first] > p.first + e[p.second][j].second) {
                cnt[i][e[p.second][j].first] = cnt[i][p.second];
                dist[i][e[p.second][j].first] = p.first + e[p.second][j].second;
                que.push(P(dist[i][e[p.second][j].first], e[p.second][j].first));
            }
        }
    }
}

void checker (ll v) {
    ali[v] = true;
    rep(i,e[v].size()) {
        if (ali[e[v][i].first]) continue;
        if (dist[0][e[v][i].first]+e[v][i].second == dist[0][v]) {
            checker(e[v][i].first);
        }
    }
}

int main(){
    cin >> n >> m;
    cin >> s >> t;
    s--; t--;
    rep(i,m) {
        ll u, v, d;
        cin >> u >> v >> d;
        u--; v--;
        e[u].push_back(P(v,d));
        e[v].push_back(P(u,d));
    }
    dijk(0, s);
    dijk(1, t);
    memset(ali, 0, sizeof(ali));
    checker(t);
    
    ll Mdis = dist[0][t];
    ll ans = 0;
    rep(i,n) {
        if (!ali[i]) continue;
        if (dist[0][i] == dist[1][i]) {
            ll tmp = cnt[0][i] * cnt[1][i] % MOD;
            tmp = tmp * tmp % MOD;
            ans = (ans+tmp)%MOD;
            continue;
        }
        rep(j,e[i].size()) {
            if (!ali[e[i][j].first]) continue;
            if (dist[0][i]*2 < Mdis && dist[1][e[i][j].first]*2 < Mdis && dist[0][i]+dist[1][e[i][j].first]+e[i][j].second == Mdis) {
                ll tmp = cnt[0][i] * cnt[1][e[i][j].first] % MOD;
                tmp = tmp * tmp % MOD;
                ans = (ans+tmp)%MOD;
            }
        }
    }
    ans = (cnt[0][t]*cnt[1][s]-ans+MOD)%MOD;
    cout << ans << endl;
}






























