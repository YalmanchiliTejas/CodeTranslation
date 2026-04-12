#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 10005, maxd = 110, mod = 1e9 + 7;
string K;
int D, n;
vector<int> digits;
ll dp[maxn][maxd][2];

ll rec(int pos, int sum, int flag) {
    if (pos == n) {
        if (sum % D == 0) {
            return 1;
        }
        return 0;
    }
    if (dp[pos][sum][flag] != -1) {
        return dp[pos][sum][flag];
    }
    int limit = (flag == 1)? digits[pos] : 9;
    ll tot = 0;
    for (int i = 0; i <= limit; i++) {
        if (i == digits[pos]) {
            tot = (tot + rec(pos + 1, (sum + i) % D, flag)) % mod;
        } else {
            tot = (tot + rec(pos + 1, (sum + i) % D, 0)) % mod;
        }
    }
    return dp[pos][sum][flag] = tot;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> K >> D;
    for (char it : K) {
        digits.push_back(it - '0');
    }
    n = digits.size();
    memset(dp, -1, sizeof(dp));
    ll answer = (rec(0, 0, 1) - 1 + mod) % mod;
    cout << answer;

    return 0;
}