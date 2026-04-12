//
// Created by PIIMUU on 8/29/2020.
//
#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;
int bipow(int x, int y) {
    int ret = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            ret = (1LL * ret * x) % MOD;
        }
        y /= 2;
        x = (1LL * x * x) % MOD;
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> suff(n + 1);
    suff[n] = a[n];
    for (int i = n - 1; i >= 1; i--) {
        suff[i] = (0LL + a[i] + suff[i + 1]) % MOD;
    }
    int answer = 0;
    for (int i = 1; i <= n - 1; i++) {
        //cout << anser << '\n';
        answer = (0LL + answer + (1LL * a[i] * suff[i + 1]) % MOD) % MOD;
       // cout << answer << " " << suff[i + 1] << '\n';
    }
    cout << answer;
}

