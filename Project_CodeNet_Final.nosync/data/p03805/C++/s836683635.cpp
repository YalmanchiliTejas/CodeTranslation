#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

int G[10][10];

int main() {
    int N, M;
    cin >> N >> M;

    memset(G, 0, sizeof(G));

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        G[a][b] = G[b][a] = 1;
    }


    // 0 -> [1 -> ... -> N - 1]
    vector<int> B(N - 1);
    for (int i = 0; i < N - 1; ++i) B[i] = i + 1;

    int ans = 0;
    do {
        bool ok = true;
        int cur = 0;
        for (int next : B) {
            if (G[cur][next]) {
                cur = next;
            } else {
                ok = false;
                break;
            }
        }
        if (ok) ++ans;

    } while (next_permutation(B.begin(), B.end()));

    cout << ans << endl;
}