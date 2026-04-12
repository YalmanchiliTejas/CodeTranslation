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
    bool check[2][110] = {{}};
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> a[i][j];
            if(a[i][j] == '#') {
                check[0][i] = 1;
                check[1][j] = 1;
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if(check[0][i] && check[1][j]) {
                cout << a[i][j];
            }
        }
        cout << endl;
    }
}