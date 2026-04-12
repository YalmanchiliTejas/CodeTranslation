#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define INF 1000000000 //1e9

bool graph[8][8] = {{}};
bool visited[8] = {};

int dfs(int x, int N) {
    bool all_visited = true;
    REP(i, N) if (!visited[i]) all_visited = false;
    if (all_visited) return 1;

    int ret = 0;
    REP(i, N) {
        if (!graph[x][i]) continue;
        if (visited[i]) continue;
        visited[i] = true;
        ret += dfs(i, N);
        visited[i] = false;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    int a, b;
    REP(i, M) {
        cin >> a >> b;
        graph[a-1][b-1] = graph[b-1][a-1] = true;
    }

    visited[0] = true;
    cout << dfs(0, N) << endl;
}