#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i=0;i<(n);++i)
const ll MOD=1e9+7;
//const ll MOD=998244353;

template<typename T>
struct TreeDiameter{
    vector<T> dp;
    vector<vector<pair<int,T>>> G;
    TreeDiameter(int n):dp(n),G(n){}
    void add_edge(int u,int v,T c){
        G[u].emplace_back(v,c);
        G[v].emplace_back(u,c);
    }
    void dfs(int v,int p,int &s){
        if (p<0) dp[v]=T(0);
        if (dp[s]<dp[v]) s=v;
        for (auto e:G[v]){
            int u=e.first;
            if (u==p) continue;
            dp[u]=dp[v]+e.second;
            dfs(u,v,s);
        }
    }
    pair<int,int> endPoints(){
        int s=0;
        dfs(s,-1,s);
        int t=s;
        dfs(t,-1,t);
        return make_pair(s,t);
    }
    T build(){
        int t=endPoints().second;
        return dp[t];
    }
    vector<T> distance(int v){
        dfs(v,-1,v);
        return dp;
    }
    vector<T> farthest(){
        int t=endPoints().second;
        auto ds=dp;
        auto dt=distance(t);
        for (int i=0;i<ds.size();++i) ds[i]=max(ds[i],dt[i]);
        return ds;
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    TreeDiameter<int> TD(n);
    rep(i,n-1){
        int s,t,w; cin >> s >> t >> w;
        TD.add_edge(s,t,w);
    }
    vector<int> ans=TD.farthest();
    rep(i,n) cout << ans[i] << endl;
}
