#include <bits/stdc++.h>

#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);--i)
#define REP(i,n) for (int i=0;i<(n);++i)
#define MOD 998244353

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, S;
    cin >> N >> S;
    int result = 0;
    vector<int> dp(S + 1);
    REP(_, N) {
        int A;
        cin >> A;
        RFOR(s, A, S + 1) {
            dp[s] = (dp[s] + dp[s - A]) % MOD;
        }
        dp[0]++;
        if (A <= S) {
            dp[A]++;
        }
        result = (result + dp[S]) % MOD;
    }
    cout << result << endl;

    return 0;
}
