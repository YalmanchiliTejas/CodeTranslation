#include <bits/stdc++.h>

typedef long long ll;
const ll MOD = 1000000007;

using namespace std;

string K;
int D, sz;
int dp[10005][105][2];

// index in the string, sum so far % D, rest=1 for restricted digit usage
int solve(int ind, int s, int rest) {
    //base case
    if (ind == sz) {
        if (s == 0)
            return 1;
        else
            return 0;
    } else if (dp[ind][s][rest] != -1)
        return dp[ind][s][rest];

    ll ans = 0;
    int md = 9;
    if (rest == 1) md = K[ind] - '0';
    for (int i = 0; i < md; i++) {
        ans = (ans + solve(ind + 1, (s + i) % D, 0)) % MOD;
    }
    if (rest == 0) {
        ans = (ans + solve(ind + 1, (s + 9) % D, 0)) % MOD;
    } else {
        ans = (ans + solve(ind + 1, (s + md) % D, 1)) % MOD;
    }
    dp[ind][s][rest] = (int)ans;
    return (int)ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> K;
    cin >> D;
    sz = K.length();

    // init dp
    for (int i = 0; i < 10005; i++) {
        for (int j = 0; j < 105; j++) {
            for (int k = 0; k < 2; k++) {
                dp[i][j][k] = -1;
            }
        }
    }

    int ans = solve(0, 0, 1);

    cout << ((ll)ans + MOD - 1) % MOD; // remove the number 0

    return 0;
}