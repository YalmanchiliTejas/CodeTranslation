#include <bits/stdc++.h>
using namespace std;

int main () {

    int N, M;
    cin >> N >> M;

    bool map[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            map[i][j] = false;
        }
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        map[a][b] = map[b][a] = true;
    }

    int path[N - 1];
    for (int i = 0; i < N - 1; i++) {
        path[i] = i + 1;
    }

    int ans = 0;
    do {
        int cur = 0;
        bool all_visitable = true;
        for (int i = 0; i < N - 1; i++) {
            int next = path[i];
            if (!map[cur][next]) {
                all_visitable = false;
                break;
            }
            cur = next;
        }
        if (all_visitable) {
            ans++;
        }
    } while (next_permutation(path, path + N - 1));

    cout << ans << endl;

    return 0;
}