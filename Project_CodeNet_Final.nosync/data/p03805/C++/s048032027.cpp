#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, a, n) for (ll i = (a); i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

const int NMAX = 8;
bool g[NMAX][NMAX];

int dfs(int v, int N, bool visited[NMAX]) {
    bool all_visited = true;

    rep(i, 0, N) if (!visited[i]) all_visited = false;
    if (all_visited) return 1;

    int ret = 0;
    rep(i, 0, N) {
        if (g[v][i] == false) continue;
        if (visited[i]) continue;

        visited[i] = true;
        ret += dfs(i, N, visited);
        visited[i] = false;
    }
    return ret;
}

int main() {
    int N, M;
    cin >> N >> M;
    rep(i, 0, M) {
        int a, b;
        cin >> a >> b;
        g[a-1][b-1] = g[b-1][a-1] = true;
    }

    bool visited[NMAX];
    memset(visited, false, sizeof(visited));
    visited[0] = true;
    cout << dfs(0, N, visited) << endl;
}