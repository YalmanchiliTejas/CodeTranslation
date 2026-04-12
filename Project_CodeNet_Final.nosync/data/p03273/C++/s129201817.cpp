#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H, W;
    cin >> H >> W;

    char a[110][110];
    int check[110][110] = {{}};
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> a[i][j];
            if (a[i][j] == '.') check[i][j] = 1;
        }
    }

    char ans[110][110];
    int h = 0;
    int w = 0;
    for (int i = 0; i < H; i++) {

        int x = 0;
        for (int j = 0; j < W; j++) {
            x += check[i][j];
        }
        if (x != W) {
            for (int k = 0; k < W; k++) {
                ans[h][k] = a[i][k];
            }
            h++;
        }
    }



    char ans2[110][110];

    for (int i = 0; i < W; i++) {
        int y = 0;
        for (int j = 0; j < H; j++) {
            y += check[j][i];
        }
        if (y != H) {
            for (int k = 0; k < H; k++) {
                ans2[k][w] = ans[k][i];
            }
            w++;
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (ans2[i][j] == '#' || ans2[i][j] == '.') printf("%c", ans2[i][j]);
        }
        printf("\n");
    }
}