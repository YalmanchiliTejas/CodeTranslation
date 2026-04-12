#include <bits/stdc++.h>

using namespace std;

int d;
string s;
const int mod = 1e9 + 7;

int dp[1000010][2][110];

int f(int pos, int flag, int sum) {
    if(pos == (int)s.size()) {
        if(sum == 0) return 1;
        return 0;
    }
    
    int lim = 9;
    if(flag) lim = s[pos] - '0';

    int  &ans = dp[pos][flag][sum];
    if(ans != -1) return ans;
    ans = 0;

    for (int i = 0; i <= lim; ++i) {
        if(flag and i == s[pos] - '0') ans += f(pos + 1, 1, (sum + i) % d);
        else ans += f(pos + 1, 0, (sum + i) % d);
        ans %= mod;
    }
    return ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> s >> d;

    cout << (f(0,1,0) - 1 + mod) % mod<< "\n";
    return 0;
}
