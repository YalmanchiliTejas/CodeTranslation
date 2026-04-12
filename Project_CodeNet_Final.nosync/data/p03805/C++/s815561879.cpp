#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MM 1000000000
#define mod MM+7
#define INF (ll)1e18
#define PI acos(-1.0)
#define NIL -1
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

const int MAX = 8;
bool G[MAX][MAX];

int dfs(int v, int n, bool visited[MAX]){
    bool all_visited = true;
    for(int i = 0; i < n; i++){
        if(visited[i] == false){
            all_visited = false;
        }
    }
    if(all_visited){
        return 1;
    }
    int ret = 0;
    for(int i = 0; i < n; i++){
        if(G[v][i] == false) continue;
        if(visited[i]) continue;

        visited[i] = true;
        ret += dfs(i,n,visited);
        visited[i] = false;
    }
    return ret;
}

int main(){
    int n, m; cin >> n >> m;
    int a[m],b[m];
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i];
        G[a[i]-1][b[i]-1] = true;
        G[b[i]-1][a[i]-1] = true;
    }
    bool visited[MAX];

    for(int i = 0; i < n; i++){
        visited[i] = false;
    }
    visited[0] = true;
    cout << dfs(0,n,visited) << endl;
    return 0;
}
