#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int n;
lli a[3002], inf = 1e+15;
vector<vector<vector<lli>>> dp(2, vector<vector<lli>>(3002, vector<lli>(3002, inf)));

lli rec(int turn, int l, int r, lli score) {
    if (r < l) return score;
    if (dp[turn][l][r] != inf) return score + dp[turn][l][r];

    lli coef = (turn) ? -1 : 1;
    lli L = rec(!turn, l+1, r, score+coef*a[l]);
    lli R = rec(!turn, l, r-1, score+coef*a[r]);
    
    if (turn==0)    dp[turn][l][r] = (L>R) ? L-score : R-score;
    else            dp[turn][l][r] = (L>R) ? R-score : L-score;

    return score + dp[turn][l][r];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i+1];

    cout << rec(0, 1, n, 0) << endl;

    return 0;
}
