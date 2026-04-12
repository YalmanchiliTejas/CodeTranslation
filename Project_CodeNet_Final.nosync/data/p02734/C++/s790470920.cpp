#include <bits/stdc++.h>
using namespace std;

long long const mod = 998244353;
long long A[3100] = {};
long long dp[3100][3100] = {};
long long sum[3100] = {};

int main() {
    int N, S; cin >> N >> S;
    for(int i=1; i<=N; ++i) cin >> A[i];

    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=S; ++j) {
            if(j < A[i]) {
                continue;
            } else if(j == A[i]) {
                dp[i][j] = i;
            } else {
                dp[i][j] = sum[j - A[i]];
            }
        }
        for(int j=1; j<=S; ++j) sum[j] = (sum[j] + dp[i][j]) % mod;
    }

    long long res = 0;
    for(int i=1; i<=N; ++i) res = (res + dp[i][S] * (N + 1 - i) % mod) % mod;
    cout << res << '\n';        
}