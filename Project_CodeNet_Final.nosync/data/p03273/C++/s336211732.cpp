#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
const int MOD = 1000000007;
int main() {
    int H, W;
    cin >> H >> W;
    string a[110][110];
    rep(i, 0, H) {
        string s;
        cin >> s;
        rep(r, 0, W) { a[i][r] = s[r]; }
    }

    rep(i, 0, H) {
        bool all = true;
        rep(r, 0, W) {
            if(a[i][r] == "#") {
                all = false;
            }
        }
        if(all) {
            rep(r, 0, W) { a[i][r] = ""; }
            a[i][W] = "no";
        }
    }
    rep(r, 0, W) {
        bool all = true;
        rep(i, 0, H) {
            if(a[i][r] == "#") {
                all = false;
            }
        }
        if(all) {
            rep(i, 0, H) { a[i][r] = ""; }
        }
    }
    rep(i, 0, H) {
        rep(r, 0, W) { cout << a[i][r]; }
        if(a[i][W] != "no") {
            cout << endl;
        }
    }
}