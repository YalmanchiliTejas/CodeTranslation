#include <bits/stdc++.h>
using namespace std;
int graph[10][10];

void solve() {
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            graph[i][j] = -1;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    vector<int> perm(N);
    for (int i = 0; i < N; ++i) {
        perm[i] = i;
    }
    int ans = 0;
    do {
        int a = perm.at(0);
        if (a != 0) continue;
        bool ok = true;
        for (int b = 1; b < N; ++b) {
            int r = graph[perm.at(a) + 1][perm.at(b) + 1];
            if (r != 1) ok = false;
            if (!ok) break;
            a = b;
        }
        if (ok) ++ans;
    } while (next_permutation(perm.begin(), perm.end()));
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
