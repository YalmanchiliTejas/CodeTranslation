#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stack>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>


int main() {

    int N, M;
    std::cin >> N >> M;
    std::vector<int> vs;
    for (int i = 0; i < N; ++i) {
        vs.push_back(i);
    }

    bool adj[8][8];

    for (int k = 0; k < 8; ++k) {
        for (int i = 0; i < 8; ++i) {
            adj[k][i] = false;
        }
    }

    int a, b;
    for (int j = 0; j < M; ++j) {
        std::cin >> a >> b;
        adj[a - 1][b - 1] = true;
        adj[b - 1][a - 1] = true;
    }

    int cnt = 0;
    do {
        if (vs[0] != 0) {
            continue;
        }
        bool ok = true;
        for (int i = 0; i < vs.size() - 1; ++i) {
            if (!adj[vs[i]][vs[i + 1]]) {
                ok = false;
                break;
            }
        }

        if (ok) {

            cnt += 1;
        }
    } while (std::next_permutation(vs.begin(), vs.end()));

    std::cout << cnt << "\n";

    return 0;
}
