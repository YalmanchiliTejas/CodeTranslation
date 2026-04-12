#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

vector<bool> seen;
int ans = 0;

void dfs(Graph &G, int v){
    seen[v] = true;
    int test = 0;
    rep(i, seen.size())if(seen[i] == true) test++;
    if(test == seen.size())ans++;
    for(auto x: G[v]){
        if(seen[x] == true)continue;
        dfs(G, x);
        seen[x] = false;
    }
}

int main(){
    int N, M;
    cin >> N >> M;
    Graph g(N);
    rep(i, M){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    seen.assign(N, false);
    dfs(g, 0);
    cout << ans << endl;

}
