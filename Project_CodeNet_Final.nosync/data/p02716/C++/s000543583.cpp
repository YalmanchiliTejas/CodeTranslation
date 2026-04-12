# include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 3;

int n, a[N];
long long pf[N], dp[N];

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pf[i] = pf[max(0, i - 2)] + a[i];
    }

    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) {
            dp[i] = max(dp[i - 2] + a[i], pf[i - 1]);
        } else {
            dp[i] = max(dp[i - 2] + a[i], dp[i - 1]);
        }
    }

    cout << dp[n] << endl;
}
