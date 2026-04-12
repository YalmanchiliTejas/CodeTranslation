#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
#define pb push_back
#define int long long
#define all(x) (x).begin(), (x).end()

using LL = long long;
using LD = long double;
using pii = pair<int, int>;
using vii = vector<pii>;

const int INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 1e4 + 5;

int D;
string s;
int dp[N][111][2];

int solve(int pos, int rem, bool less) {
    if (pos == s.size()) {
        return rem == 0;
    }

    if (dp[pos][rem][less] != -1) {
        return dp[pos][rem][less];
    }

    int ans = 0;
    if (less) {
        for (int d = 0; d <= 9; d++) {
            int nrem = (rem + d) % D;
            ans = (ans + solve(pos + 1, nrem, less)) % MOD; 
        }
    } else {
        for (int d = 0; d <= s[pos] - '0'; d++) {
            if (d == s[pos] - '0') {
                int nrem = (rem + d) % D;
                ans = (ans + solve(pos + 1, nrem, 0)) % MOD;
            } else {
                int nrem = (rem + d) % D;
                ans = (ans + solve(pos + 1, nrem, 1)) % MOD;
            }
        }
    }

    return dp[pos][rem][less] = ans;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> s >> D;

    for (int i = 0; i <= s.size(); i++) {
        for (int j = 0; j < 111; j++) {
            dp[i][j][0] = dp[i][j][1] = -1;
        }
    }

    cout << (solve(0, 0, 0) - 1 + MOD) % MOD << "\n";   
}
