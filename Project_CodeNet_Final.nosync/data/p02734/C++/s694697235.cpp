
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 3001;
const int MOD = 998244353;
int a[N];
int n, s;
ll dp[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll ans = 0;
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        dp[0]++;
        for (int j = s; j >= a[i]; --j) {
            dp[j] += dp[j - a[i]];
            dp[j] %= MOD;
        }
        ans = (ans + dp[s]) % MOD;
    }

    cout << ans << endl;

    return 0;
}

