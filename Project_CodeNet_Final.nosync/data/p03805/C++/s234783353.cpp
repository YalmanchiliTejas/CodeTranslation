#include <iostream>
using namespace std;

const int MAX_M = 28;
const int MAX_N = 8;

int N, M;
int dist[MAX_M+1][MAX_M+1];
int flag[MAX_N+1];
int res = 0;

int dfs(int pos, int depth) {
    flag[pos] = 1;
    for(int i = 1; i <= N; i++) {
        if(dist[pos][i] == 1 && flag[i] != 1) {
            dfs(i, depth+1);
            flag[i] = 0;
        } 
    }
    if(depth == N-1) res++;
    return res;
}

void solve() {
    int ans = dfs(1, 0);
    cout << ans << endl;
}

int main() {
    cin >> N >> M;
    for(int i= 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        dist[a][b] = dist[b][a] = 1;
    }
    solve();
    return 0;
}