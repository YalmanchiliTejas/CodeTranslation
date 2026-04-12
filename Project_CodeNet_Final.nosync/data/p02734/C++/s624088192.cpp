#include<bits/stdc++.h>

constexpr int MAXN = 3e3 + 3;
constexpr int M = 998244353;

using namespace std;
using LL = long long;

LL dp[MAXN][MAXN], sum[MAXN][MAXN];
int n, S, a[MAXN];

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> S;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        (dp[i][a[i]] += i) %= M;
        for (int s = a[i] + 1; s <= S; s++) {
            (dp[i][s] += sum[i - 1][s - a[i]]) %= M;
        }
        for (int s = 0; s <= S; s++) {
            (sum[i][s] = sum[i - 1][s] + dp[i][s]) %= M;
        }
    }
    LL res = 0;
    for (int i = 1; i <= n; i++)
        (res += dp[i][S] * (n - i + 1) % M) %= M;
    cout << res << endl;
    return 0;
}