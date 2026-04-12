#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
typedef long long ll;

int dfs(vector<vector<int>> &graph, int v, set<int> s){

    s.insert(v);
    if(s.size() == graph.size()){   //全ての頂点（n個）を訪問したら完了
        return 1;
    }

    int res = 0;
    for(int e : graph[v]){
        if(s.count(e)){
            continue;   //訪問済みなら(集合の中にあるなら)次のノード訪問する
        }
        res += dfs(graph, e, s);
    }
    return res;
}

int main() {

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

    int ans = dfs(graph, 0, {}); //始点0、集合｛｝

    cout << ans << endl;

    return 0;
}