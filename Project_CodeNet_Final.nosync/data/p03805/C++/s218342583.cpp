#include <bits/stdc++.h>
using namespace std;

vector<bool> seen;

/*
//深さ優先探索
void dfs(const vector<vector<int>> &g, int v){
    seen.at(v) = true;

    for (auto next_v: g.at(v)){
        if(seen.at(next_v)) continue;
        dfs(g, next_v);
    }
}
*/

int proc_dfs(const vector<vector<int>> &g, int v){
    bool b = true;
    for (bool s: seen){
        if (s == false) b = false;
    }
    if (b == true) {
        return 1;
    }

    int ret = 0;
    for (auto next_v: g.at(v)){
        if(seen.at(next_v) == true) continue;
        seen.at(next_v) = true;
        ret += proc_dfs(g, next_v);
        seen.at(next_v) = false;
    }
    return ret;
}

int main() {
    int n, m;
    cin >> n >> m;

    int a, b;
    vector<vector<int>> g(n);
    for(int i=0; i<m; i++){
        cin >> a >> b;
        a--; b--;
        g.at(a).push_back(b);
        g.at(b).push_back(a);
    }

    seen.assign(n, false);

    seen.at(0) = true;
    cout << proc_dfs(g, 0) << endl;
    return 0;
}
