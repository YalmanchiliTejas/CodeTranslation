#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
const ll nmax=8;
bool graph[nmax][nmax];

ll dfs(ll v,ll n,bool visited[nmax]){
    bool ok=true;
    for(ll i=0;i<n;i++){
        if(visited[i]==false){
            ok=false;
        }
    }
    if(ok) return 1;
    ll ret=0;
    for(ll i=0;i<n;i++){
        if(graph[v][i]==false) continue;
        if(visited[i]) continue;
        visited[i]=true;
        ret+=dfs(i,n,visited);
        visited[i]=false;
    }
    return ret;
}
int main() {
    ll n,m;
    cin >> n >> m;
    for(ll i=0;i<m;i++){
        ll a,b;
        cin >> a >> b;
        a--;b--;
        graph[a][b]=graph[b][a]=true;
    }
    bool visited[nmax];
    for(ll i=0;i<n;i++) visited[i]=false;
    visited[0]=true;
    cout << dfs(0,n,visited) << endl;
}