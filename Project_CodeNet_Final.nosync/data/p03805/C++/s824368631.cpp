#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
vector<vector<int> > G(10, vector<int>(10, 0));
vector<int> visited(10, 0);
int N;
int ans = 0;
/* function */
void dfs(int from, int cnt) {
    cnt++;
    if (cnt == N) {
        ans++;
        return;
    }
    visited[from] = 1;
    for (int to = 0; to < N; to++) {
        if (G[from][to] == 0) continue;
        if (visited[to]) continue;
        dfs(to, cnt);
    }
    cnt--;
    visited[from] = 0;
}
/* main */
int main(){
    int M, a, b;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        a--; b--;
        G[a][b] = 1;
        G[b][a] = 1;
    }
    int st = 0;
    for (int i = 0; i < N; i++) if (G[i].size() == 1) st = i;
    dfs(st, 0);
    cout << ans << '\n';
}
