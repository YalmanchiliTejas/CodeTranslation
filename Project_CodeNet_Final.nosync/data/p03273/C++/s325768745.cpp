#include "bits/stdc++.h"

using namespace std;
using ll = long long;

char G[105][105];

int main() {
    int H, W;
    cin >> H >> W;

    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            cin >> G[i][j];

    vector<bool> height(H), width(W);
    for (int h = 0; h < H; ++h) {
        height[h] = false;
        for (int w = 0; w < W; ++w)
            if (G[h][w] == '#') {
                height[h] = true;
                break;
            }
    }
    for (int w = 0; w < W; ++w) {
        width[w] = false;
        for (int h = 0; h < H; ++h)
            if (G[h][w] == '#') {
                width[w] = true;
                break;
            }
    }

    for (int h = 0; h < H; ++h) {
        if (!height[h])
            continue;
        for (int w = 0; w < W; ++w) {
            if (width[w])
                cout << G[h][w];
        }
        cout << endl;
    }
}
