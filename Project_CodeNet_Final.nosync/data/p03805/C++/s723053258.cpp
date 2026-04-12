#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> con(8, vector<bool> (8, false));
vector<bool> visited(8,false);

int dfs(int v, int n, vector<bool> visited) {
    bool flag = true;
    for(int i = 0; i < n; i++) {
        if(visited.at(i) == false)
        flag = false;
    }
    if(flag) return 1;
    
    int ret = 0;
    for(int i = 0; i < n; i++) {
        if(con.at(v).at(i) == false) continue;
        if(visited.at(i)) continue;
        
        visited.at(i) = true;
        ret += dfs(i, n, visited);
        visited.at(i)=false;
    }
    return ret;
}

int main(void){
    int n,m; cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--; b--;
        con.at(a).at(b) = true;
        con.at(b).at(a) = true;
    }
    visited.at(0) = true;
    cout << dfs(0, n, visited) << endl;
    
}
