#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> Pii;

constexpr int MOD = 998244353;

int main() {
    int N, S; cin >> N >> S;
    vector<ll> A(N); for (int i = 0; i < N; i++) cin >> A[i];

    vector<vector<ll>> memo(N, vector<ll>(3001, 0));

    ll ans = 0;
    memo[0][A[0]] = 1;
    if (A[0] == 0) ans += N;
    for (int i = 1; i < N; i++) {
        if (S == A[i]) {
            ans += ((N-i) * (i+1)) % MOD;
            ans %= MOD;
        } else if (S > A[i]) {
            ans += (memo[i-1][S-A[i]] * (N-i)) % MOD;
            ans %= MOD;
        }
        for (int j = 1; j < S+1; j++) {
            if (j > A[i]) {
                if (memo[i-1][j-A[i]] != 0) memo[i][j] = memo[i-1][j] + memo[i-1][j-A[i]];
                else memo[i][j] = memo[i-1][j];
            } else if (j == A[i]) {
                memo[i][j] = memo[i-1][j] + i + 1;
            } else {
                memo[i][j] = memo[i-1][j];
            }
            memo[i][j] %= MOD;
        }
    }
    cout << ans << endl;
}
