//Darker and Darker
#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

using Graph = vector<vector<int> >;
Graph G;

void dfs(int v, vector<bool> &seen, int &res){
    bool end = true;
    rep(i, seen.size()){
        if(!seen.at(i) && i != v) end = false;
    }
    if(end){
        res++;
        return;
    }
    seen.at(v) = true;
    for(int nv : G.at(v)){
        if(seen.at(nv)) continue;
        dfs(nv, seen, res);
    }
    seen.at(v) = false;
}

int main(){
    int N, M;
    cin >> N >> M;
    G.assign(N, vector<int>());
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G.at(a).push_back(b);
        G.at(b).push_back(a);
    }
    vector<bool> seen(N, false);
    int res = 0;
    dfs(0, seen, res);
    cout << res << endl;

    return 0;
}