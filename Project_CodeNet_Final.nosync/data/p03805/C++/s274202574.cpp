#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i,n) for(int i= 0; i<n; i++)

vector<bool> visit_edges(10,false);
vector<int> to[30];

int dfs(int v,int n,vector<bool> visit_edges){
    int ans = 0;
    bool finish = true;
    visit_edges[v] = true;
    rep(i,n){
        if(!visit_edges[i]) finish = false;
    }
   
    if (finish) return 1;
    for( int e: to[v]){
        if (visit_edges[e]) continue;
        ans += dfs(e,n,visit_edges);
    }
    return ans;
}

int main(){
    int n,m,ans;
    cin >> n >> m;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    ans = dfs(0,n,visit_edges);
    cout << ans << endl;
    return 0;
}