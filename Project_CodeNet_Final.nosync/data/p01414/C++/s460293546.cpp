#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>

using namespace std;

const int INF = 1 << 30;

inline int enc(int x, int y) { return x + y * 4; }

int main() {
    int N;
    cin >> N;

    set<int> paint;  // 選べる長方形領域
    for (int i = 0; i < N; ++i) {
        int H, W;
        cin >> H >> W;

        // 左下を軸に全探索
        for (int lx = -3; lx <= 3; ++lx) {
            for (int ly = -3; ly <= 3; ++ly) {
                int pat = 0;
                for (int dx = 0; dx < H; ++dx) {
                    for (int dy = 0; dy < W; ++dy) {
                        int x = lx + dx, y = ly + dy;
                        if (x < 0 || 4 <= x || y < 0 || 4 <= y) continue;
                        pat |= (1 << enc(x, y));
                    }
                }
                paint.insert(pat);
            }
        }
    }

    vector<string> S(4);
    for (auto& s : S) cin >> s;

    // BFS
    queue<int> que;
    que.push((1 << 16) - 1);

    vector<int> dist(1 << 16, INF);
    dist[(1 << 16) - 1] = 0;

    while (!que.empty()) {
        int v = que.front();
        que.pop();

        // 長方形領域と色を全探索
        for (auto pat : paint) {
            for (char c : string("RGB")) {
                int sv = v;
                for (int x = 0; x < 4; ++x) {
                    for (int y = 0; y < 4; ++y) {
                        if ((pat >> enc(x, y)) & 1) {
                            sv &= ~(1 << enc(x, y));
                            sv |= (S[x][y] != c) << enc(x, y);
                            // 一度bitを消してから、「同じか否か」で書き換える
                            // 同じなら0とする
                        }
                    }
                }

                if (dist[sv] == INF) {
                    dist[sv] = dist[v] + 1;
                    que.push(sv);
                }
            }
        }
    }

    cout << dist[0] << endl;
    return 0;
}

