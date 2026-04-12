#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> edges[100000];
    for(int i=0; i<N-1; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    vector<pair<int, int>> dp[100000];
    auto dfs = [&](auto&& dfs, int i, int p)->void{
        dp[i].emplace_back(0, i);
        for(int j : edges[i]) if(j != p){
            dfs(dfs, j, i);
            dp[i].emplace_back(dp[j][0].first+1, j);
        }
        sort(dp[i].rbegin(), dp[i].rend());
    };
    dfs(dfs, 0, -1);

    vector<int> ng(2*N+1);

    auto dfs2 = [&](auto&& dfs2, int i, int p, int u)->void{
        vector<int> vs(3);
        vs.push_back(u);
        for(auto& p : dp[i]) vs.push_back(p.first);
        sort(vs.rbegin(), vs.rend());
        int v1 = vs[0], v2 = vs[2];
        if(v2 > 0){
            if(v1 == v2){
                ng[v1+v2-1] = 1;
            }else{
                ng[v1+v2] = 1;
            }
        }
        for(int j : edges[i]) if(j != p){
            int u2 = u+1;
            for(int k=0; k<2; k++) if(dp[i][k].second != j) u2 = max(u2, dp[i][k].first+1);
            dfs2(dfs2, j, i, u2);
        }
    };
    dfs2(dfs2, 0, -1, 0);
    for(int i=2*N; i>0; i--) if(ng[i]) ng[i-1] = 1;
    ng[1] = ng[2] = 0;
    for(int i=1; i<=N; i++) cout << 1-ng[i];
    cout << endl;
    return 0;
}

