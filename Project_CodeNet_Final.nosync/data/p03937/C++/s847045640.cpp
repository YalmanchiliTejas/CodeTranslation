#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    for (int i = 0; i < H; i++) {
        cin >> A[i];
    }
    queue<pair<int, int>> que;
    que.push({0, 0});
    vector<vector<int>> dist(H, vector<int>(W, 1e9));
    dist[0][0] = 0;
    while (!que.empty()) {
        int h = que.front().first;
        int w = que.front().second;
        que.pop();
        if (h + 1 < H && A[h + 1][w] == '#') {
            dist[h + 1][w] = dist[h][w] + 1;
            que.push({h + 1, w});
        }
        if (w + 1 < W && A[h][w + 1] == '#') {
            dist[h][w + 1] = dist[h][w] + 1;
            que.push({h, w + 1});
        }
    }

    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (dist[h][w] == 1e9 && A[h][w] == '#') {
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }

    for (int h0 = 0; h0 < H; h0++) {
        for (int w0 = 0; w0 < W; w0++) {
            for (int h1 = 0; h1 < H; h1++) {
                for (int w1 = 0; w1 < W; w1++) {
                    if (h0 == h1 && w0 == w1) {
                        continue;
                    }
                    if (dist[h0][w0] == 1e9 || dist[h1][w1] == 1e9) {
                        continue;
                    }

                    if (dist[h0][w0] == dist[h1][w1]) {
                        cout << "Impossible" << endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout << "Possible" << endl;
}
