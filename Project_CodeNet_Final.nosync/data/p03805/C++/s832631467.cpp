#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define REP(i, d, n) for(int i=(d); i<(n); ++i)
#define all(v) v.begin(), v.end()
using ll = long long;
using P = pair<int, int>;

vector<vector<int>> graph;
vector<bool> visit;
int ans = 0;
int n;

void dfs(int v){
    visit[v] = true;
    int flag = true;
    rep(i, n){
        if(!visit[i]){
            flag = false;
            break;
        }
    }
    if(flag){
        ans++;
    }
    
    for(auto u : graph[v]){
        if(visit[u]){
            continue;
        }
        dfs(u);
    }
    visit[v] = false;
}


int main() {

    int m;
    cin >> n >> m;
    graph.resize(n);
    visit.resize(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(0);

    cout << ans << endl;

    return 0;
}
