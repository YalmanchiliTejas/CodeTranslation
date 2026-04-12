#include <bits/stdc++.h>

using namespace std;

int n;

int a[30], dp[30], ans = 1, pref[30];

int main () {
    cin >> n;
    for (int i = 1;i <= n;i ++) {
        cin >> a[i];
        pref[i] = max (pref[i - 1], a[i]);
    }
    for (int i = 2;i <= n;i ++) {
        if (pref[i - 1] <= a[i]) ans ++;
    }cout << ans;
}
