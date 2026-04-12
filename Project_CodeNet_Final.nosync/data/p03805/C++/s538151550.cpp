#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 8;
vector<int> G[MAX_V + 1];
int ans = 0;
bool used[MAX_V + 1];

void dfs(int n, int no_used) {
    used[n] = true;

    if (no_used == 0) ans++;

    for (int i = 0; i < G[n].size(); i++) {
        if (!used[G[n][i]]) {
            dfs(G[n][i], no_used - 1);
        }
    }
    used[n] = false;
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(1, N - 1);
    cout << ans << endl;

    return 0;
}