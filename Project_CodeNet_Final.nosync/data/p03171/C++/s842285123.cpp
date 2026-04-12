#include<bits/stdc++.h>
using namespace std;
#define MAXN 3000
#define LL long long int

int N, a[MAXN + 3];
LL dp[MAXN + 3][MAXN + 3], total;

LL solve(int l, int r) {
    if (l > r)
        return 0;
    
    if (dp[l][r] != -1)
        return dp[l][r];

    LL lft = a[l] + min(solve(l + 2, r), solve(l + 1, r - 1));
    LL rght = a[r] + min(solve(l, r - 2), solve(l + 1, r - 1));

    return dp[l][r] = max(lft, rght);
}

int main() {
    cin >> N;

    total = 0;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        total += a[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << 2 * solve(1, N) - total << endl;
}
