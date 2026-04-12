#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000

bool G[8][8];

int dfs(int v, int N, bool visited[8]){
    bool all = true;
    rep(i, N) if(visited[i] == false) all = false;
    if (all) return 1;

    int ret = 0;
    rep(i, N) {
        if(G[v][i] == false) continue;
        if(visited[i] == true) continue;

        visited[i] = true;
        ret += dfs(i, N, visited);
        visited[i] = false;
    }

    return ret;
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    int a[M], b[M];
    rep(i, M) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        G[a[i]][b[i]] = true;
        G[b[i]][a[i]] = true;
    }

    bool visited[8];
    rep(i, 8) visited[i] = false;

    visited[0] = true;
    cout << dfs(0, N, visited) << endl;

    return 0;
}
