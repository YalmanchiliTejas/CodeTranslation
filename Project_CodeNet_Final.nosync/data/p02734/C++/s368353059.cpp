#include <bits/stdc++.h>
using namespace std;
  
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

const int N = 3005, MOD = 998244353;
int dp[N], a[N];

void add(int &a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s;
    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        if (s - a[i] >= 0) {
            ans = (ans + dp[s - a[i]] * (ll)(n - i)) % MOD;
        }

        if (a[i] == s) {
            ans = (ans + (i + 1) * (ll)(n - i)) % MOD;
        }

        for (int j = s - a[i]; j >= 0; j--) {
            add(dp[j + a[i]], dp[j]);
        }

        add(dp[a[i]], i + 1);
    }

    cout << ans << "\n";

    return 0;   
}   