#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<ll,ll> P;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define EFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i, n) FOR(i,0,n)
#define IINF 1e9

int DFS(Graph& q, vector<bool>& vis, int x, int n){
    bool can = true;
    int tot = 0;
    REP(i,n){
        if(!vis[i]) can = false;
    }
    if(can) return 1;
    REP(i,n){
        if(q[x][i] == -1) continue;
        if(vis[i]) continue;
        vis[i] = true;
        tot += DFS(q,vis,i,n);
        vis[i] = false;        
    }
    return tot;
}

int main(void){
    int n,m;
    cin >> n >> m;
    Graph q(n,vector<int>(n,-1));
    vector<bool> vis(n,false);

    REP(i,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        q[a][b] = 1;
        q[b][a] = 1;
    }
    vis[0] = true;
    cout << DFS(q,vis,0,n) << endl;
    return 0;
}