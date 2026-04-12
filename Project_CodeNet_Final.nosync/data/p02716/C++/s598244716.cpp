#include <bits/stdc++.h>
// clang-format off
using namespace std; using ll = int64_t; using ull = uint64_t; const ll INF = 9e18;
void print() { cout << endl; }
template<typename Head,typename... Tail> void print(Head head,Tail... tail){cout<<head;if(sizeof...(Tail)>0)cout<<" ";print(tail...);}
void print0() {}
template<typename Head,typename... Tail> void print0(Head head,Tail... tail){cout<<head;print0(tail...);}
// clang-format on

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }
    ll half = N / 2;
    ll maxskip = (N % 2 == 0) ? 1 : 2;
    vector<vector<ll>> dp(maxskip + 1, vector<ll>(N, -INF));
    if (N % 2 == 0) {
        dp[0][0] = A[0];
        dp[1][1] = A[1];
        if (N > 2) {
            dp[0][2] = A[0] + A[2];
        }
        for (ll i = 3; i < N; i++) {
            dp[0][i] = dp[0][i - 2] + A[i];
            dp[1][i] = max(dp[1][i - 2] + A[i], dp[0][i - 3] + A[i]);
        }
        ll result = max(dp[0][N - 2], dp[1][N - 1]);
        print(result);
    } else {
        dp[0][0] = A[0];
        dp[1][1] = A[1];
        if (N > 2) {
            dp[2][2] = A[2];
            dp[0][2] = A[0] + A[2];
        }
        if (N > 3) {
            dp[1][3] = max(A[1] + A[3], A[0] + A[3]);
        }
        for (ll i = 4; i < N; i++) {
            dp[0][i] = dp[0][i - 2] + A[i];
            dp[1][i] = max(dp[1][i - 2] + A[i], dp[0][i - 3] + A[i]);
            dp[2][i] = max(max(dp[2][i - 2] + A[i], dp[1][i - 3] + A[i]), dp[0][i - 4] + A[i]);
        }
        ll result = max(max(dp[0][N - 3], dp[1][N - 2]), dp[2][N - 1]);
        print(result);
    }
}
