
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> dp(n);
    dp[0] = 0;
    dp[1] = std::max(a[0], a[1]);
    dp[2] = std::max(dp[1], a[2]);
    ll oddSum = a[0] + a[2]; //a[0]+a[2]+...と、奇数番目の要素のみを足したもの。
    for (int i = 3; i < n; i++) {
        if (i % 2 == 0) {
            dp[i] = std::max(dp[i - 3] + a[i - 1], dp[i - 2] + a[i]);
            oddSum += a[i];
        }
        else {
            dp[i] = std::max(oddSum, dp[i - 2] + a[i]);
        }
    }
    cout << dp[n - 1] << endl;

    return 0;

}
