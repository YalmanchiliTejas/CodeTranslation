#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 3010, M = 998244353;
ll n, s, a[N], dp[N];

int main() {
    cin >> n >> s;
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = s - a[i]; j >= 1; j--) {
            dp[j + a[i]] = (dp[j + a[i]] + dp[j]) % M;
        }
        dp[a[i]] += i;
        ans = (ans + dp[s]) % M;
    }
    cout << ans << "\n";
}
