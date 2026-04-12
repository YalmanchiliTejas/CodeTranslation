#include<iostream>
#include<vector>
using namespace std;
int main() {
    int h, w;
    cin >> h >> w;
    const int N = 100;
    char a[N][N];
    for (int i = 0; i < h; ++i) {
        cin >> a[i];
    }
    int f[N], g[N];
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (a[i][j] == '#') {
                f[i] = g[j] = 1; //#がある行、列を出力
            }
        }
    }
    for (int i = 0; i < h; ++i) {
        if (f[i]) {
            for (int j = 0; j < w; ++j) {
                if (g[j]) {
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }
    return 0;
}
