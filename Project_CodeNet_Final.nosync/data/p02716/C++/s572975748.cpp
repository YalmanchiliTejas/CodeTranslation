#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;

template <class T>
void chmax(T &a, T b) {
    if (b > a) a = b;
}

ll dp[3][200000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m = 1 + n % 2;//余裕の個数

    for (int k = 0; k <= m; k++) {
        for (int i = 0; i < n; i++) {
            dp[k][i] = -(1LL << 60);
        }
    }

    for (int i = 0; i <= m; i++) {
        dp[i][i] = a[i];
    }

    for (int i = 2; i < n; i++) {
        for (int k = 0; k <= m; k++) {
            chmax(dp[k][i], dp[k][i - 2] + a[i]);
        }
        if (i - 3 < 0) continue;
        for (int k = 1; k <= m; k++) {
            chmax(dp[k][i], dp[k - 1][i - 3] + a[i]);
        }
        if (i - 4 < 0) continue;
        for (int k = 2; k <= m; k++) {
            chmax(dp[k][i], dp[k - 2][i - 4] + a[i]);
        }
    }

    ll r = -(1LL << 60);
    for (int k = 0; k <= m; k++) {
        chmax(r, dp[k][n - 1 - (m - k)]);
    }

    //for (int k = 0; k <= m; k++) {
    //    for (int i = 0; i < n; i++) {
    //        cout << dp[k][i] << ' ';
    //    }
    //    cout << '\n';
    //}

    cout << r << endl;

    return 0;
}