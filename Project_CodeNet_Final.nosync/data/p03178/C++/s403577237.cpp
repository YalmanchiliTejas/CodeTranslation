#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MN = 1e4 + 5, MOD = 1e9 + 7;
ll dp[MN][105];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int d; string s;
    cin >> s >> d;
    int N = s.length();
    reverse(s.begin(), s.end());
    ll ans = 0;
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < d; j++) {
            for (int k = 0; k < 10; k++) {
                (dp[i][(j + k) % d] += dp[i - 1][j]) %= MOD;
            }
        }
    } 
    int sum = 0;
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < s[i] - '0'; j++) {
            (ans += dp[i][(d - (sum + j) % d) % d]) %= MOD;
        }
        sum += s[i] - '0';
    }
    if (sum % d == 0) ans++;
    cout << (ans - 1 + MOD) % MOD << '\n';
    return 0;
}