#include <bits/stdc++.h>

using namespace std;

int n;
int square[15][15];

int solve(int x, int y, int cnt) {

    if(cnt > n * n) return 0;

    if(square[y][x]) {
        solve(n - 1 - ((n - 1 - x) + 1) % n, (y + 1) % n, cnt);
    } else {
        square[y][x] = cnt;
        solve((x + 1) % n, (y + 1) % n, cnt + 1);
    }

}

int main() {

    while(cin >> n, n) {

        memset(square, 0, sizeof(square));

        solve(n / 2, n / 2 + 1, 1);

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                printf("%4d", square[i][j]);
            }
            cout << endl;
        }

    }

}