#include <bits/stdc++.h>
using namespace std;

int N, M, A[30], B[30], ans;
vector< vector<int> > G(9);

void dfs(int node, vector<bool> vis){
    bool res = true;
    for(int i=1;i<=N;i++){
        if( !vis[i] ){
            res = false;
            break;
        }
    }
    if( res ){
        ans++;
        return;
    }

    for(int i=0;i<G[node].size();i++){
        if( !vis[ G[node][i] ] ){
            vis[ G[node][i] ] = true;
            dfs(G[node][i], vis);
            vis[ G[node][i] ] = false;
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i=0;i<M;i++)    cin >> A[i] >> B[i];

    for(int i=0;i<M;i++){
        G[ A[i] ].push_back(B[i]);
        G[ B[i] ].push_back(A[i]);
    }

    vector<bool> vis(N+1);
    for(int i=1;i<=N;i++)   vis[i] = false;

    vis[1] = true;
    ans = 0;
    dfs(1, vis);

    cout << ans << endl;
}