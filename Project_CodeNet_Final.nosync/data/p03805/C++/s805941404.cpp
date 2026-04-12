#include <bits/stdc++.h>

using namespace std;

#define all(c) (c).begin(), (c).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M;
int G[10][10];
int ans = 0;

void dfs(int v, int S) {
    if (S + 1 == 1 << N) {
        ans++;
    }
    rep(i, N) {
        if (G[v][i]) {
            if (S >> i & 1) continue;
            dfs(i, S | 1 << i);
        }
    }
}

int main() {
    cin >> N >> M;
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a][b] = G[b][a] = 1;
    }
    dfs(0, 1);
    cout << ans << endl;
    return 0;
}
