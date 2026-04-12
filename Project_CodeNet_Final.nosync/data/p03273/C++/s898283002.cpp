#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> a(H, vector<char>(W));
    vector<vector<char>> tmp(H, vector<char>(W));
    vector<vector<char>> ans(H, vector<char>(W));
    rep(i, H) {
        rep(j, W) {
            cin >> a[i][j];
        }
    }
    int cnt = 0;
    rep(i, H) {
        bool flag = false;
        rep(j, W) {
            if (a[i][j] == '#') {
                flag = true;
                break;
            }
        }
        if (flag) {
            rep(j, W) {
                tmp[cnt][j] = a[i][j];
            }
            cnt += 1;
        }
    }
    cnt = 0;
    rep(j, W) {
        bool flag = false;
        rep(i, H) {
            if (tmp[i][j] == '#') {
                flag = true;
                break;
            }
        }
        if (flag) {
            rep(i, H) {
                ans[i][cnt] = tmp[i][j];
            }
            cnt += 1;
        }
    }
    rep(i, H) {
        rep(j, W) {
            if (ans[i][j] == '#' | ans[i][j] == '.') cout << ans[i][j];
        }
        cout << '\n';
    }
    return 0;
}