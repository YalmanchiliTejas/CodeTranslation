#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int main() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++)cin >> a[i];

    ll ret = 0;
    vector<ll> dp(s + 1);
    for (int i = 0; i < n; i++) {
        if (a[i] <= s) {
            dp[a[i]] += i + 1;
            for (int j = s; j >= a[i]; j--) {
                dp[j] += dp[j - a[i]];
                if (j - a[i] == a[i])dp[j] -= i + 1;
                dp[j] += MOD, dp[j] %= MOD;
            }
        }
        ret += dp[s] % MOD, ret %= MOD;
    }

    cout << ret << endl;
    return 0;
}