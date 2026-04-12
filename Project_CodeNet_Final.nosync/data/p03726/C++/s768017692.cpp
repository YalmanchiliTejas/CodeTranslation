#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll MOD = 1000000007;

vector<vector<int>> G;

int dfs(int v, int par){
    int ret = 0;
    for(int to : G[v]){
        if(to == par) continue;
        ret += dfs(to, v);
    }
    // cout << v << " " << ret << endl;
    if(ret == 0){
        return 1;
    }else if(ret == 1){
        return 0;
    }else{
        return 2;
    }
}

int main(){
    int N;
    cin >> N;

    G.assign(N, {});
    for(int i=0;i<N-1;i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    if(dfs(0, -1) >= 2 || dfs(G[0][0], -1) >= 2){
        cout << "First" << endl;
    }else{
        cout << "Second" << endl;
    }

    return 0;
}