#include <bits/stdc++.h>
// clang-format off
using namespace std; using ll = int64_t; using ull = uint64_t; const ll INF = 9e18;
void print() { cout << endl; }
template<typename Head,typename... Tail> void print(Head head,Tail... tail){cout<<head;if(sizeof...(Tail)>0)cout<<" ";print(tail...);}
void print0() {}
template<typename Head,typename... Tail> void print0(Head head,Tail... tail){cout<<head;print0(tail...);}
// clang-format on

ll dpval(vector<vector<ll>> &dp, ll i, ll j) {
    if (j >= 0) {
        return dp[i][j];
    }
    return -INF;
}
int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }

    if (N % 2 == 0) {
        vector<vector<ll>> dp(2, vector<ll>(N, -INF));
        dp[0][0] = A[0];
        dp[1][1] = A[1];
        for (ll i = 2; i < N; i++) {
            dp[0][i] = A[i] + dpval(dp, 0, i - 2);
            dp[1][i] = A[i] + max(dpval(dp, 1, i - 2), dpval(dp, 0, i - 3));
        }
        ll result = max(dpval(dp, 0, N - 2), dpval(dp, 1, N - 1));
        print(result);
    } else {
        vector<vector<ll>> dp(3, vector<ll>(N, -INF));
        dp[0][0] = A[0];
        dp[1][1] = A[1];
        dp[2][2] = A[2];
        dp[0][2] = A[0] + A[2];
        for (ll i = 3; i < N; i++) {
            dp[0][i] = A[i] + dpval(dp, 0, i - 2);
            dp[1][i] = A[i] + max(dpval(dp, 1, i - 2), dpval(dp, 0, i - 3));
            dp[2][i] = A[i] + max(max(dpval(dp, 2, i - 2), dpval(dp, 1, i - 3)), dpval(dp, 0, i - 4));
        }
        ll result = max(max(dpval(dp, 0, N - 3), dpval(dp, 1, N - 2)), dpval(dp, 2, N - 1));
        print(result);
    }
}
