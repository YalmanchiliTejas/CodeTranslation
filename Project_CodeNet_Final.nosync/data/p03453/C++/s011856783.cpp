#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define F first
#define S second
#define int long long
#define ll long long
//#define int  unsigned long long
#define pb push_back
#define double long double

using namespace std;
using namespace __gnu_pbds;
typedef  tree< int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int N = 1000000;
const int K = 19;
const int mod = 1e9 + 7;
int dp[2][N], s, t, n, m, d[2][N], c[2][N];
vector < int > gr[2][N];
vector < pair < int, int > > g[N];
void solve(int k){
    vector < pair < int, int > > a;
    for (int i = 1; i <= n; i++) if (d[0][i] + d[1][i] == d[0][t]) a.pb({d[0][i], i});
    sort(a.begin(), a.end());
    if (k == 1) reverse(a.begin(), a.end());
    if (k == 1) dp[k][t] = 1; else dp[k][s] = 1;
    for (auto i: a){
        int v = i.S;
        for (auto u: gr[k][v]){
            dp[k][u] = (dp[k][u] + dp[k][v]) % mod;
         //   cout << k << " " << u << " " << dp[k][u] << " v = " << v << endl;
        }
    }
}
void dist(int k){
    for (int i = 1; i <= n; i++) d[k][i] = 1e18;
    set < pair < int, int > > q;
    if (k == 0){
        q.insert({0, s});
        d[k][s] = 0;
    }
    else{
        q.insert({0, t});
        d[k][t] = 0;
    }
    while(!q.empty()){
        int v = (*q.begin()).S;
        q.erase(q.begin());
        for (auto u: g[v]){
            if (d[k][u.F] > d[k][v] + u.S){
                q.erase({d[k][u.F], u.F});
                d[k][u.F] = d[k][v] + u.S;
                q.insert({d[k][u.F], u.F});
            }
        }
    }
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    cin >> s >> t;
    for (int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    dist(0);
    dist(1);

   // for (int i = 1; i <= n; i++) cout << d[0][i] << " " << d[1][i] << endl;;
   // cout << endl;
    int cnt = 0;
    for (int v = 1; v <= n; v++){
        for (auto u: g[v]){
            if (d[0][v] + d[1][u.F] + u.S != d[0][t] || d[0][v] > d[0][u.F]) continue;
            gr[0][v].pb(u.F);
            gr[1][u.F].pb(v);
          //  cout << v << " " << u.F << endl;
            if (2 * d[0][v] < d[0][t] && 2 * d[0][u.F] > d[0][t]){
                c[0][cnt] = v;
                c[1][cnt] = u.F;
                cnt++;
            }
        }
        if (2 * d[0][v] == d[0][t] && 2 * d[1][v] == d[1][s]){
            c[0][cnt] = v;
            c[1][cnt] = v;
            cnt++;
        }
    }
    solve(0);
    solve(1);
    int s1 = 0;
    int s2 = 0;
    int ans = 0;
    for (int i = 0; i < cnt; i++){
        int u = c[0][i];
        int v = c[1][i];
       // cout << u << " -- " << v << " " << dp[0][u] << " --- " << dp[1][v] << endl;
        int x = dp[0][u] * dp[1][v] % mod;
        x = x * x % mod;
        ans = (ans - x + mod) % mod;
    }
    cout << (ans + dp[0][t] * dp[1][s]) % mod;
}
