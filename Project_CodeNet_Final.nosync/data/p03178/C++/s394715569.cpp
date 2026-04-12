#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

const int N = 1e4 + 100;
const int D = 128;

int dp[N][D][2];

int main() {
    ios::sync_with_stdio(false);
    string s;
    int d;
    cin >> s >> d;
    int n = s.size();
    dp[0][0][1] = 1;
    for (int i=0; i<n; i++) {
        for (int m=0; m<d; m++) {
            for (int eq=0; eq<=1; eq++) {
                for (int x=0; x<=9; x++) {
                    if (eq && x > s[i]-'0') {
                        continue;
                    }
                    int m2 = (m + x) % d;
                    int eq2 = eq && x == s[i]-'0';
                    dp[i+1][m2][eq2] = (dp[i+1][m2][eq2] + dp[i][m][eq]) % MOD;
                }
            }
        }
    }
    ll ans = (dp[n][0][0] + dp[n][0][1] + MOD - 1) % MOD;
    cout << ans << '\n';
}
