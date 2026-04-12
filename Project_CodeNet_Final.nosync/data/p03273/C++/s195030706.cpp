#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;

int H, W;
char a[100][100];

int main() {
    cin >> H >> W;
    rep(i, H)rep(j, W) cin >> a[i][j];

    // 縦 
    char ans1[100][100];

    rep(i, W) {
        int all_white = true;
        rep(j, H) {
            // cout << a[j][i];
            if (a[j][i] == '#') {
                all_white = false;
                break;
            }  
        }
        // cout << endl;

        if (all_white) {
            rep(j, H) {
                a[j][i] = 'x';
            }
        }
    }

    // 横
    rep(i, H) {
        int all_white_row = true;
        rep(j, W) {
            if (a[i][j] == '#') {
                all_white_row = false;
                break;
            }
        }

        if (all_white_row) {
            rep(j, W) {
                a[i][j] = 'x';
            }
        }
    }

    // cout << endl;
    rep(i, H) {
        int tmp = 0;
        rep(j, W) {
            if (a[i][j] == 'x') {
                tmp++;
                continue;
            }
            cout << a[i][j];
        }

        if (tmp != W) {
            cout << endl;
        }
    }
}