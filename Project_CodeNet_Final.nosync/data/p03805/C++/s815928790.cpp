#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
#define drep(i,cc,n) for(int i=cc;i>=n;--i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const long long INF = 1LL <<60;
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) {
    if (b==0) return a;
    else return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

ll choose2(ll n){
    return n*(n-1)/2;
}

int n,m;
ll ans = 0;

void dfs(int v, vector<vector<int>> &g, vector<bool> vis){

    vis[v] = true;

    bool end = true;
    rep(i,0,n-1) if(vis[i] == false) end = false;
    if(end == true){
        ans++;
        return;
    }

    /*rep(i,0,n-1) cout<<vis[i];
    cout<<endl;*/

    //vis[v] = true;
    for(int nv : g[v]){
        if(vis[nv] == true) continue;
        dfs(nv, g, vis);
    }
}

int main(){
    cin>>n>>m;
    vector<vector<int>> g(n);
    vector<bool> vis(n,false);
    rep(i,0,m-1){
        int a,b;
        cin>>a>>b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(0,g,vis);

    cout<<ans<<endl;
    return 0;
}