#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
using namespace std;
typedef pair<ll, ll> pll;


ll n, m, s , t;
vector< pll > g[100005];
vector< pair<pll, ll> > M;
ll dist[2][100005];
ll ways[2][100005];
ll D;
const ll mod = 1e9 + 7;
void gos(ll src, ll id)
{
        for (int i=1;i<=n;i++)
                dist[id][i]=1e16;
        ways[id][src]=1;
        dist[id][src]=0;
        multiset<pll> sett; sett.clear();
        for (int i=1;i<=n;i++)
        {
         sett.insert(make_pair(dist[id][i],i));
        }

        for (int iter=1;iter<=n;iter++)
        {
         auto it=sett.begin();
         ll qv=(*it).second;
         ll qcost=(*it).first;
         sett.erase(it);
         for (int i=0;i<g[qv].size();i++)
         {
          ll tv=g[qv][i].first;
          ll tcost=g[qv][i].second+qcost;
          if (tcost>dist[id][tv])continue;
          if (tcost==dist[id][tv]){
                        ways[id][tv] = (ways[id][tv] + ways[id][qv])%mod;
                        continue;
          }
          sett.erase(make_pair(dist[id][tv],tv));
          dist[id][tv]=tcost;
          ways[id][tv]=ways[id][qv];
          sett.insert(make_pair(dist[id][tv],tv));
         }
        }
}
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
        cin >> n >> m;
        cin >> s >> t;
        for(ll i=1;i<=m;i++) {
                ll u,v,d;
                cin >> u >> v >> d;
                g[u].pb(make_pair(v, d));
                g[v].pb(make_pair(u, d));
                M.pb(make_pair(make_pair(u,v) , d));
        }
        gos(s, 0);
        gos(t, 1);
        D = dist[0][t];
        //cout << D << endl; return 0;
        if(D >= 1e16) {
                cout << "0\n"; return 0;
        }
        ll sum = 0;
        ll yo = 0;

        for(ll i=1;i<=n;i++) {
                if(D%2 == 1) break;
                ll xx = D/2;
                if(dist[0][i] == xx && dist[1][i] == xx){
                        //cout << i << " ---- ";
                        ll ay = (ways[0][i]*ways[1][i])%mod;
                        //cout << ay << endl;
                        sum = (sum + (ways[0][i] * ways[1][i])%mod + mod)%mod;
                        yo = (yo + (ay*ay)%mod + mod)%mod;
                }
        }
        for(auto &i : M) {

                ll u = i.first.first;
                ll v = i.first.second;
                ll w = i.second;
                if(dist[0][u] > dist[0][v]) swap(u, v);
                if(dist[0][u] + w + dist[1][v] == D && dist[0][u] < (D+1)/2 && dist[1][v] < (D+1)/2 && dist[0][u]+w > (D+1)/2 && dist[1][v]+w > (D+1)/2) {
                        //cout << u << " **** " << v << endl;
                        ll ay = (ways[0][u]*ways[1][v])%mod;
                        sum = (sum + (ay%mod) + mod)%mod;
                        yo  = (yo + (ay*ay)%mod + mod)%mod;
                }
        }
        ll ans = (sum*sum)%mod;
        ans = (ans - (yo) + mod)%mod;
        cout << ans << endl;
        return 0;
}
