#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < n; i++)

int n;
int A[3030];
ll dp[3030][3030];
int flag[3030][3030];

ll rec(int l, int r) {
    if(flag[l][r]) return dp[l][r];

    flag[l][r] = 1;

    if (l == r) return dp[l][r] = A[l];
    return dp[l][r] = max(A[l] - rec(l + 1, r), A[r] - rec(l, r - 1));
}

int main() {
    cin >> n;
    rep(i, n) cin >> A[i];
    rep(i, 3030) rep(j, 3030) dp[i][j] = -(1LL << 58);
    cout << rec(0, n - 1) << endl;
    return 0;
}
