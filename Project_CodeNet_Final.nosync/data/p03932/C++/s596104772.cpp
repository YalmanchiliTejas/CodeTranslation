#include <bits/stdc++.h>
using namespace std;

template<class T1, class T2>
void chmax(T1 &a, T2 b) {
    if (a < b) a = b;
}

int h, w, a[200][200];
int dp[200][200][200];

const int dy[] = { 0, 1 };
const int dx[] = { 1, 0 };

int main() {
    cin >> h >> w;
    for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) cin >> a[i][j];
    fill_n(**dp, 200 * 200 * 200, -1e9);

    dp[0][0][0] = a[0][0];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            for (int ii = 0; ii < h; ii++) {
                int jj = (i + j) - ii;
                for (int k = 0; k < 2; k++) {
                    for (int kk = 0; kk < 2; kk++) {
                        int ni = i + dy[k];
                        int nj = j + dx[k];
                        int nii = ii + dy[kk];
                        int njj = jj + dx[kk];
                        if (ni >= h || nii >= h || nj >= w || njj >= w) continue;
                        int gain = 0;
                        if (ni == nii && nj == njj) {
                            gain = a[ni][nj];
                        } else {
                            gain = a[ni][nj] + a[nii][njj];
                        }
                        chmax(dp[ni][nj][nii], dp[i][j][ii] + gain);
                    }
                }
            }
        }
    }

    cout << dp[h - 1][w - 1][h - 1] << endl;
}