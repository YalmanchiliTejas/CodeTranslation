#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repk(i, k, n) for (int i = k; i < n; i++)
#define MOD 1000000007
#define INF 1e9
#define PIE 3.14159265358979323

template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
T GCD(T a, T b) {
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}
template <class T>
inline T LCM(T a, T b) {
    return (a * b) / GCD(a, b);
}

using namespace std;
//#inculude <bits/stdc++.h>
#define int long long

signed main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> tbl(h, vector<char>(w));
    rep(i, h) rep(j, w) cin >> tbl[i][j];
    vector<bool> flg_h(h, false);
    vector<bool> flg_w(w, false);
    rep(i, h) {
        bool flag = true;
        rep(j, w) {
            if (tbl[i][j] == '#')
                flag = false;
        }
        if (flag)
            flg_h[i] = true;
    }
    rep(i, w) {
        bool flag = true;
        rep(j, h) {
            if (tbl[j][i] == '#')
                flag = false;
        }
        if (flag)
            flg_w[i] = true;
    }
    /* rep(i, h) cout << flg_h[i];
    cout << endl;
    rep(i, w) cout << flg_w[i];
    cout << endl; */
    rep(i, h) rep(j, w) {
        if (!flg_h[i] && !flg_w[j])
            cout << tbl[i][j];
        if (j == w - 1 && !flg_h[i])
            cout << endl;
    }
}
