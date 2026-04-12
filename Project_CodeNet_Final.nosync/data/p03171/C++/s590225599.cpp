#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define MAXN 3009

ll dp[MAXN][MAXN], n, seq[MAXN];

ll calc(int i, int j, bool taro){
    if (dp[i][j] != -1) return dp[i][j];
    if (i == j && taro) return dp[i][j] = seq[i];
    if (i == j && !taro)    return dp[i][j] = 0;
    if (taro)
        return dp[i][j] =  max(seq[i] + calc(i + 1, j, !taro), seq[j] + calc(i, j - 1, !taro));
    return dp[i][j] = min(calc(i + 1, j, !taro), calc(i, j - 1, !taro));
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    memset(dp, -1, sizeof dp);
    ll sum = 0;
    cin >> n;
    rep(i, 0, n)cin >> seq[i], sum += seq[i];
    cout << calc(0, n - 1, 1) - ((ll)sum - dp[0][n-1]) << '\n';
    return 0;
}
