#include <iostream>
#include <vector>
#include <set>
using namespace std;

int dfs(vector<vector<int>> const& g, int v, vector<bool>& used, set<int> vs) {
    vs.insert(v);
    if(vs.size() == g.size()) {
        return 1;
    }
    int res = 0;
    for(int i=0; i<g.size(); ++i) {
        if(g[v][i] == 1 && !used[i]) {
            used[v] = true;
            res += dfs(g, i, used, vs);
            used[v] = false;
        }
    }
    return res;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> g(N, vector<int>(N));
    for(int i=0; i<M; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a][b] = g[b][a] = 1;
    }
    set<int> s;
    s.insert(0);
    vector<bool> used(N, false);
    used[0] = true;
    cout << dfs(g, 0, used, s) << endl;
}
