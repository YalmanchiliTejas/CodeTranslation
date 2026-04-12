#include <bits/stdc++.h>
 
using namespace std;

const int maxn  = 3123456;

int n;
vector < int > adj[maxn];
int mat[maxn];
bool ok = 0;
 
void dfs(int v , int par = 0){
    for(auto u : adj[v])
        if(u!=par){
            dfs(u, v);
            if(mat[u] == 0 and mat[v] == 0)
                mat[u] = 1 , mat[v] = 1;
        }
}
 
int main(){
    cin >> n;
    for(int i = 1 ; i < n ; i ++){
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1 ; i <= n ; i ++)
        if(adj[i].size()> 1 ){
            dfs(i);
            break;
        }
    ok = 1;
    for(int i = 1 ; i <= n ; i ++)
        ok&=(mat[i]!=0);
    if(n==2)ok=1;
    cout << ((!ok) ? "First" : "Second");
    return(0);
}