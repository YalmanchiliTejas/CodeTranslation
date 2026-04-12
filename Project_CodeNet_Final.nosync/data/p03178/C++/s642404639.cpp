#include <bits/stdc++.h>
#define pii pair <int, int>
#define pb push_back
#define mp make_pair
using namespace std;
const long long MOD = 1e9 + 7;
int N, K;
string s;
int A[103];
int dp[10005][100], dp2[10005][100], eq[10005];
int main() {
    cin >> s >> K;
    N = s.length();
    //reverse(s.begin(), s.end());
    for (int j = 1; j < 10; ++j)
        dp[0][j % K]++;
    for (int i = 1; i < N - 1; ++i)
        for (int j = 0; j <= 9; ++j)
            for (int k = 0; k < K; ++k)
                dp[i][ (j + k) % K] = (dp[i][ (j + k) % K] + dp[i - 1][k]) % MOD;
    int cnt = 0;
    for (int i = 0; i < N - 1; ++i)
        cnt = (cnt + dp[i][0]) % MOD;

    for (int j = 1; j < s[0] - '0'; ++ j)
        dp2[0][j % K]++;
    eq[0] = (s[0] - '0') % K;
    for (int i = 1; i < N; ++i) {
        eq[i] = (eq[i - 1] + s[i] - '0') % K;
        for (int j = 0; j <= 9; ++j) {
            for (int k = 0; k < K; ++k) {
                dp2[i][ (j + k) % K] = (dp2[i][ (j + k) % K] + dp2[i - 1][k]) % MOD;
            }
            if (j < s[i] - '0') dp2[i][(j + eq[i - 1]) % K]++;
        }
    }
    cout << (cnt + dp2[N - 1][0] + (eq[N - 1] == 0)) % MOD;
    return 0;
}
