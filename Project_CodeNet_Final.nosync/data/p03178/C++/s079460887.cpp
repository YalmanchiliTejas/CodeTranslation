#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
typedef long long ll;
string s;
int d;

ll dp[100008][2][128];

ll dfs(int pos, int less, int sum) {
    if (pos == s.size()) {
        if (sum % d == 0) {
            return 1;
        } else {
            return 0;
        }
    }
    if (dp[pos][less][sum] != -1) {
        return dp[pos][less][sum];
    }
    char upper = less ? '9' : s[pos];
    ll total = 0;
    for (char i = '0'; i <= upper; i++) {
        ll num = sum + i - '0';
        num %= d;
        total += dfs(pos + 1, less || i < upper, num) % M; 
        total %= M;
    }
    total %= M;
    return dp[pos][less][sum] = total;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    cin >> d;
    memset(dp, -1, sizeof(dp));
    cout << max((dfs(0, 0, 0) - 1LL + M) % M, 0LL);
    return 0;
}
