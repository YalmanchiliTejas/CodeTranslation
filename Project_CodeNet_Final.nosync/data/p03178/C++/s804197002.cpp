#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;
typedef vector<pii> vii;
typedef map<ll, ll> mii;
const int MOD = 1e9 + 7;

#define fastIO() \
ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define mp make_pair 

string K;
int D;

int main() {
    cin >> K >> D;
    int n = K.length();
    vector<vi> dp(D, vi(2));
    // dp[i][j] says how many nums such that sum is i mod D and 
    // j = 0 indicates smaller than K so far, j = 1 indicates moving at full capacity
    for (int i = 0; i < K[0]-'0'; ++i) {
        dp[i % D][0] += 1;
    }
    dp[(K[0] - '0') % D][1] = 1;
    for (int i = 1; i < n; ++i) {
        vector<vi> new_dp(D, vi(2));
        for (int sum = 0; sum < D; ++sum) {
            for (int digit = 0; digit < K[i] - '0'; ++digit) {
                new_dp[(sum + digit) % D][0] += (dp[sum][0] + dp[sum][1]);
                new_dp[(sum + digit) % D][0] %= MOD;
            }
            new_dp[(sum + K[i] - '0') % D][0] += dp[sum][0];
            new_dp[(sum + K[i] - '0') % D][0] %= MOD;
            new_dp[(sum + K[i] - '0') % D][1] += dp[sum][1];
            new_dp[(sum + K[i] - '0') % D][1] %= MOD;
            for (int digit = K[i] - '0' + 1; digit <= 9; ++digit) {
                new_dp[(sum + digit) % D][0] += dp[sum][0];
                new_dp[(sum + digit) % D][0] %= MOD;
            }
        }
        // for (int j = 0; j < D; ++j)
        //     cerr << dp[j][0] << " " << dp[j][1] << endl;
        // cerr << "*" << endl;
        dp = new_dp;
    }
    // for (int j = 0; j < D; ++j) cerr << dp[j][0] << " " << dp[j][1] << endl;
    //     cerr << "*" << endl;
    ll ans = dp[0][0] + dp[0][1];
    ans = (ans + MOD - 1) % MOD;    //subtracting num = 0 case
    cout << ans << endl;
    return 0;
}
