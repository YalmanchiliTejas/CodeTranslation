#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;

const double PI=acos(-1.0);

const int nmax = 8;
bool g[nmax][nmax];

int dfs(int p, int N, bool seen[nmax]) {
    bool all_seen = true;

    rep(i, N) if(!seen[i]) all_seen = false;

    if(all_seen) return 1;

    int ret = 0;
    rep(i, N) {
        if(!g[p][i]) continue;
        if(seen[i]) continue;

        seen[i] = true;
        ret += dfs(i, N, seen);
        seen[i] = false;
    }

    return ret;
}

int main() {
    int n, m;
    cin >> n >> m;
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a][b] = g[b][a] = true;
    }

    bool seen[nmax];
    rep(i, n) seen[i] = false;

    seen[0] = true;

    cout << dfs(0, n, seen) << endl;
    
    return 0;
}

