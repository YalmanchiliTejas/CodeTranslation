#include <iostream>
#include <vector>
using namespace std;

using Graph = vector<vector<int>>;
Graph G;

void dfs(int v, vector<bool> &seen, int &res){
    bool end = true;
    for(int i = 0; i < seen.size(); i++) {
        if(!seen.at(i) && i != v) end = false;
    }
    if(end) {
        ++res;
        return;
    }
    
    seen.at(v) = true;
    for(auto nv : G.at(v)) {
        if(seen.at(nv)) continue;
        dfs(nv, seen, res);
    }
    seen.at(v) = false;
}

int main(void){
    int n,m; cin >> n >> m;
    G.assign(n,vector<int>());
    for(int i = 0; i < m; i++) {
        int a,b; cin >> a >> b; a--,b--;
        G.at(a).push_back(b);
        G.at(b).push_back(a);
    }
    vector<bool> seen(n, false);
    int res = 0;
    dfs(0,seen,res);
    cout << res << endl;
}
