#include <bits/stdc++.h>
#define ll long long
#define lsb(x) (x & -x)

using namespace std;

const int MOD = 1000000007;

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

int main() {
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);
    //freopen("a.in", "r", stdin);

    string s;
    int d;
    cin >> s >> d;
    int ndigits = s.size();

    vector<vector<int>> dp(d, vector<int> (ndigits + 1, 0));
    dp[0][0] = 1;

    for(int i = 0; i < ndigits; i ++)
        for(int r = 0; r < d; r ++)
            for(int digit = 0; digit < 10; digit ++)
                dp[(r + digit) % d][i + 1] = (dp[(r + digit) % d][i + 1] + dp[r][i]) % MOD;

    int ans = dp[0][ndigits - 1];
    ans --; // il scot pe 0
    if(ans < 0)
        ans += MOD;

    int sumofdigits = (d * 10 - (s[0] - '0')) % d;
    for(int digit = 1; digit < s[0] - '0'; digit ++) {
        ans += dp[(d * 10 - digit) % d][ndigits - 1];
        mod(ans);
    }

    for(int i = 1; i < s.size(); i ++) {
        for(int digit = 0; digit < s[i] - '0'; digit ++) {
            ans += dp[(sumofdigits + d * 10 - digit) % d][ndigits - i - 1];
            mod(ans);
        }

        sumofdigits = (sumofdigits + d * 10 - (s[i] - '0')) % d;
    }

    if(sumofdigits == 0) {
        ans ++;
        mod(ans);
    }

    cout << ans;

    return 0;
}
