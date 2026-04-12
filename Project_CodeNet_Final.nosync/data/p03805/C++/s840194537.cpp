#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define pf push_front
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a) for(int i = a; i >= 0; i--)
#define fori(i,m) for(auto i = m.begin(); i != m.end(); i++) 
#define sz(s) int(s.size())
#define cls(a,car) memset(a,car,sizeof (a))
using namespace std;
typedef long long ll;
const int N = 1 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
vector<int> G[10];
int n,m;
int vis[15];
bool check(){
    fore(i,0,n)
        if(vis[i] == -1)
            return 0;
    return 1;
}
int dfs(int u){
    if(check())
        return 1;

    int ans = 0;
    fore(i,0,sz(G[u])){
        int v = G[u][i];
        if(vis[v] == 1)
            continue;
        vis[v] = 1;
        ans += dfs(v);
        vis[v] = -1;
    }
    return ans;
}
int main(){/*
    freopen("in","r",stdin);
    freopen("out","w",stdout);*/
    fast;
    cin >> n >> m;
    while(m--){
        int u,v;
        cin >> u >> v;
        u--;v--;
        G[u].pb(v);
        G[v].pb(u);
    }
    cls(vis,-1);
    vis[0] = 1;
    cout << dfs(0) << '\n';
    return 0;   
}