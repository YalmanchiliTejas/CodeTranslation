#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

string s;
int k;

int dp[105][2][5];

int rec(int id, int tight, int left) {
    if (left < 0)   return 0;
    if (id == (int)s.size())    return left == 0;
    int &ans = dp[id][tight][left];
    if (ans != -1)  return ans;
    ans = 0;
    int lim = tight ? s[id] - '0' : 9;
    for (int i = 0; i <= lim; i++) 
        ans += rec(id + 1, (i < s[id] - '0') ? 0 : tight, left - (i > 0));
    return ans;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> s >> k;
    memset(dp, -1, sizeof dp);
    cout << rec(0, 1, k);
}