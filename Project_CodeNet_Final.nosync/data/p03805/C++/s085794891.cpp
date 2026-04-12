#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000

bool G[8][8];

int dfs(int v, int N, bool vis[8]) {
    
    bool all_vis = true;
    rep(i, N) {
        if(vis[i] == false) all_vis = false;
    }

    if(all_vis) return 1;

    int ret = 0;

    for (int i = 0; i < N; i++) {
        if (G[v][i] == false) continue;
        if (vis[i]) continue;

        vis[i] = true;
        ret += dfs(i, N, vis);
        vis[i] =false;
    }

    return ret;
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;

    rep(i, M) {
        int A, B;
        cin >> A >> B;
        A--; B--;
        G[A][B] = true; G[B][A]= true;
    }

    bool vis[8];
    rep(i, 8) vis[i] = false;

    vis[0] = true;
    cout << dfs(0, N, vis) << endl;
    return 0;

    return 0;
}
