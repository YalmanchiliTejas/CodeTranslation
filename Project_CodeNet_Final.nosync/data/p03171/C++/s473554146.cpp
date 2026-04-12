#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int a[3010];
ll dp[3010][3010][2]; /// dp table

ll go(int l, int r, bool turn) {
    if(r < l) return 0;

    if(dp[l][r][turn] != -1) return dp[l][r][turn];

    ll op1 = (turn ? -a[l] : a[l]) + go(l + 1, r, !turn);
    ll op2 = (turn ? -a[r] : a[r]) + go(l, r - 1, !turn);

    if(!turn) return dp[l][r][turn] = max(op1, op2);
    else return dp[l][r][turn] = min(op1, op2);
}

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    memset(dp, -1, sizeof dp);

    cout << go(0, n - 1, 0) << endl;
}

/*
 * L
**/
