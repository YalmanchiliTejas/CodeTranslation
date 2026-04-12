// 4/23
// 順列組み合わせの練習

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
    int N, M;
    cin >> N >> M;

    Graph G(N);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        G[a].push_back(b);
        G[b].push_back(a);
    }

    int perm[100];
    for (int i = 0; i < N; i++) {
        perm[i] = i;
    }

    int ans = 0;
    do {
        if (perm[0] != 0) continue;

        bool is_pass = false;

        for (int i = 0; i < N - 1; i++) {
            is_pass = false;

            int from = perm[i];
            int to = perm[i + 1];

            // printf("from, to = %d %d\n", from, to);

            for (auto x : G[from]) {
                if (x == to) {
                    // printf("x, to = %d %d\n", x, to);
                    is_pass = true;
                    break;
                }
            }

            if (!is_pass) {
                break;
            }
        }

        if (is_pass) {
            // cout << "ans++" << endl;
            ans++;
        }

    } while (next_permutation(perm, perm + N));

    cout << ans << endl;
}
