#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
vector<bool> seen;
int c = 0;
int N;
ll ans = 0;
void dfs(Graph &G, int v){
    seen[v] = true;
    c++;
    if(c==N){
        ans++;
        return;
    }
    for (auto next_v:G[v])
    {
        if(seen[next_v])continue;
        dfs(G, next_v);
        c--;
        seen[next_v] = false;
    }
    
}
int main(){
    int M;
    cin >> N >> M;
    Graph G(N+1);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    seen.assign(N+1, false);
    dfs(G, 1);
    cout << ans << endl;
}