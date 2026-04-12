#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

using lint = long long;
using ldouble = long double;

const int INF = 1 << 30;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> D(M);
    map<int, int> rev;
    for (int i = 0; i < M; ++i) {
        cin >> D[i];
        rev[--D[i]] = i;
    }

    vector<vector<int>> path(N, vector<int>(K));
    for (auto& v : path) {
        for (auto& e : v) {
            cin >> e;
            --e;
        }
    }

    vector<vector<int>> graph(1 << M);
    for (int b = 0; b < (1 << M); ++b) {
        for (int a = 0; a < K; ++a) {
            int tob = 0;

            for (int i = 0; i < M; ++i) {
                if (!((b >> i) & 1)) continue;
                int to = path[D[i]][a];
                if (!rev.count(to)) continue;
                tob |= (1 << rev[to]);
            }

            graph[b].push_back(tob);
        }
    }

    vector<int> dist(1 << M, INF);
    dist[(1 << M) - 1] = 0;
    queue<int> que;
    que.push((1 << M) - 1);

    while (!que.empty()) {
        int v = que.front();
        que.pop();

        for (auto sv : graph[v]) {
            if (dist[sv] < INF) continue;
            dist[sv] = dist[v] + 1;
            que.push(sv);
        }
    }

    cout << dist[0] << endl;
    return 0;
}

