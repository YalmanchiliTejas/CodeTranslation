#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
#define rep2(i,a,n) for (int i = a; i < n; i++)
using namespace std;
int N;
long long A[100001];
long long dp[100001];
long long INF = pow(10, 12);

void input() {
    cin >> N;
    rep(i, N) {
        cin >> A[i];
        A[i] *= -1;
    }
    rep(i, 100001) {
        dp[i] = INF;
    }
}

void solve() {
    rep(i, N) {
        int key = upper_bound(dp, dp + N, A[i]) - dp;
        dp[key] = A[i];
    }
    int ans = 0;
    ans = lower_bound(dp, dp + N, INF) - dp;

    printf("%d\n", ans);

}
int main() {
    input();
    solve();
    return 0;
}
