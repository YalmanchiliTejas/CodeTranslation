#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

ll ans = 0;

ll dfs(ll n, ll d, ll point, vector<vector<ll>> g, vector<ll> check){
    if(d == n){
        ans++;
        return 0;
    }
    if(d > n) return 0;
    for(auto x:g[point]){
        vector<ll> tmp = check;
        if(check[x] < 0){
            tmp[x] = 1;
            dfs(n, d+1, x, g, tmp);
        }
    }
    return 0;
}

int main(){
    ll n, m; cin >> n >> m;
    vector<ll> a(m), b(m); rep(i,m) cin >> a[i] >> b[i];

    vector<vector<ll>> g(n+1);
    for(int i = 0; i < m; i++){
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }

    vector<ll> check(n+1,-1);
    check[1] = 1;
    dfs(n,1,1,g,check);
    put(ans);
}