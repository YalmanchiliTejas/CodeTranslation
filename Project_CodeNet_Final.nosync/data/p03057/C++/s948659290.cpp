#include <bits/stdc++.h>
using namespace std;

#define SZ(x) (int)(x).size()
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i, a, b) for (int i=a;i>=b;--i)

const int MX_N = 2e5+5;
const int MX_M = 2e5+5;
const int MOD = 1e9+7;

int N, M;
string S;

int dp[MX_N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    cin >> S;

    bool same = true;
    FOR(i,0,M-1){
        same &= S[i] == S[0];
    }

    if (same) {
        // dp[i]: no of ways to color s.t. no 2 consec is B & i-th is R
        int ans = 0;
        dp[1] = 0; dp[2] = 1;   // 1st is B
        FOR(i,3,N){
            dp[i] = (dp[i-1] + dp[i-2]) % MOD;
        }
        ans = (ans + dp[N]) % MOD;           // Nth is R
        dp[1] = 1; dp[2] = 1;   // 1st is R
        FOR(i,3,N){
            dp[i] = (dp[i-1] + dp[i-2]) % MOD;
        }
        ans = (ans + (dp[N] + dp[N-1]) % MOD) % MOD; // Nth is R and B
        cout << ans;
        return 0;
    }

    if (N&1) {
        cout << 0;
        return 0;
    }

    int k = N, kp = N, cur = 0;
    FOR(i,0,M-1){
        if (S[i] != S[0]) {
            if (k == N) {
                if (cur&1) k = cur;
                else k = cur+1;
            } else if (cur&1) kp = min(kp,cur);
            cur = 0;
        } else ++cur;
    }

    int L = min({N-1,k,kp});
    N /= 2, L /= 2;

    //cout << "L is " << L << endl;

    dp[0] = 0; dp[1] = 1;
    int sum = 0;
    FOR(i,2,N){
        if (i-(L+2) >= 1) {
            sum = (sum - dp[i-(L+2)] + MOD) % MOD;
        }
        if (i-1 >= 1) {
            sum = (sum + dp[i-1]) % MOD;
        }
        dp[i] = sum;
    }

    int ans = 0;
    FOR(i,0,L){
        ans = (ans +  1LL * (i+1) * dp[N-i] % MOD) % MOD;
    }
    cout << ans * 2 % MOD;
}

