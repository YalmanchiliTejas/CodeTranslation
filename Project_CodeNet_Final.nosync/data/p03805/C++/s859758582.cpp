#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

static const int N = 8;
bool mat[N][N];
int n;

int dfs(int s){
    int cnt = 0;
    bool visited[N];
    rep(i, n) visited[i] = false;

    function<void(int, int)> dfs_rec = [&](int u, int d){
        visited[u] = true;
        if(d == n) cnt++;
        rep(i, n)
            if(mat[u][i] && !visited[i]){
                dfs_rec(i, d + 1);
                visited[i] = false;
            }
        return;
    };
    dfs_rec(s, 1);
    return cnt;
}

int main(){
    int m, a, b;
    cin >> n >> m;
    rep(i, n){
        rep(j, n) mat[i][j] = false;
        mat[i][i] = true;
    }
    rep(i, m){
        cin >> a >> b;
        a--, b--;
        mat[a][b] = true;
        mat[b][a] = true;
    }

    cout << dfs(0) << endl;
    return 0;
}