#include <bits/stdc++.h>
using namespace std;
using Int = long long;
template <class T> void chmax(T &x, T y) { if (x < y) x = y; }
int A[200][200], B[200][200];
int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int H, W; cin >> H >> W;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            for (int k = j + 1; k < W; k++) {
                B[j][k] = B[j][k] + A[i][j] + A[i][k];
            }
        }
        for (int k = 0; k < W; k++) {
            for (int j = 0; j + 1 < k; j++) {
                chmax(B[j + 1][k], B[j][k] + A[i][j + 1]);
            }
        }
        for (int j = 0; j < W; j++) {
            for (int k = j + 1; k + 1 < W; k++) {
                chmax(B[j][k + 1], B[j][k] + A[i][k + 1]);
            }
        }
        for (int k = 0; k < W; k++) {
            for (int j = 0; j + 1 < k; j++) {
                chmax(B[j + 1][k], B[j][k]);
            }
        }
    }
    cout << B[W - 2][W - 1] << endl;
    return 0;
}
