#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
string n; int k;
int digit[111];
LL dp[111][111];
LL dfs(int pos, int nonzero, bool limit) {
    if (pos==n.size()) {
        return nonzero == k;
    }
    if (!limit && dp[pos][nonzero] != -1) return dp[pos][nonzero];
    int up = limit ? digit[pos] : 9;
    LL ret = 0;
    for (int i = 0; i <= up; i++) {
        ret += dfs(pos + 1, nonzero + (i != 0), limit && i == digit[pos]);
    }
    if (!limit) dp[pos][nonzero] = ret;
    return ret;
}
int main() {
    memset(dp, -1L, sizeof dp);
    cin >> n >> k;
    for (int i = 0; i < n.size();i++) digit[i] = n[i]-'0';
    cout << dfs(0, 0, true) << endl;
}