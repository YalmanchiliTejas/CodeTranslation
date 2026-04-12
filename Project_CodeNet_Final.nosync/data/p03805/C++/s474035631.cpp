#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int INF = 1e9;

int dp[1 << 10][10];
int V,E,s,t;
vector<vector<int> > G;

int rec(int bit = 1, int v = 0){
    if(dp[bit][v]>0) return dp[bit][v];
    if(bit == (1<<V)-1) return 1;
    int ret = 0;
    for(int nv : G[v]){
        if(bit & (1<<nv)) continue;
        ret += rec(bit | (1<<nv), nv);
    }
    return dp[bit][v] = ret;
}

int main(){
    cin >> V >> E;
    G.resize(V);
    for(int i = 0; i < E; ++i){
        cin >> s >> t;
        --s; --t;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    cout << rec() << endl;
    return 0;
}

