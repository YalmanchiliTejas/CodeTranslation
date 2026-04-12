#include <bits/stdc++.h>
using namespace std;
long long dp[200001][5];
long long A[200000];

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int ans = 0;
    int tmp = min(X,Y);
    ans += min(A + B, 2 * C) * tmp;
    X -= tmp;
    Y -= tmp;

    if(Y == 0) ans += min(A, 2 * C) * X;
    if(X == 0) ans += min(B, 2 * C) * Y;

    cout << ans << endl;
}