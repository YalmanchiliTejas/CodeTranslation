#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

void add_self(ll& a, ll b) {
    a += b;
    if(a > mod) {
        a -= mod;
    }
}

int main()
{
    string K;
    int D;
    cin >> K >> D;

    //dp[i][j] - no.of ways such that sum of digits % D is i.
    // j = 0 - number is not less than K. j = 1 - number is less than K already.
    vector<vector<ll>> dp(D, vector<ll>(2));
    dp[0][0] = 1;

    for(int i = 0; i < (int)K.length(); i++) {
        vector<vector<ll>> new_dp(D, vector<ll>(2));
        for(int d = 0; d < 10; d++) {
            if(d < K[i]-'0') {
                for(int j = 0; j < D; j++) {
                    add_self(new_dp[(j+d)%D][1], dp[j][1]);
                    add_self(new_dp[(j+d)%D][1], dp[j][0]);
                }
            }
            else if(d == K[i]-'0') {
                for(int j = 0; j < D; j++) {
                    add_self(new_dp[(j+d)%D][1], dp[j][1]);
                    add_self(new_dp[(j+d)%D][0], dp[j][0]);
                }
            }
            else {
                for(int j = 0; j < D; j++) {
                    add_self(new_dp[(j+d)%D][1], dp[j][1]);
                }
            }
        }
        dp = new_dp;
    }
    ll ans = dp[0][1] + dp[0][0] - 1;
    if(ans > mod) {
        ans -= mod;
    }
    cout << ans << endl;
}
