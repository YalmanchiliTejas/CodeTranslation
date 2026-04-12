#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i) 
#define PI acos(-1)

using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin>>N;
    vector<ll> as(N);
    rep(i, N) cin>>as[i];

    vector<vector<ll>> dp(N + 1, vector<ll>(N + 1));
    int i, j;
    rep(i, N) {
        rep(j, N - i) {
            int l = j;
            int r = j + i;
            if ((N + i) % 2 == 0) {  // jiro
                dp[i + 1][j] = min(dp[i][j + 1] - as[l], dp[i][j] - as[r]);
            }
            else {  // taro
                dp[i + 1][j] = max(dp[i][j + 1] + as[l], dp[i][j] + as[r]);
            }
        }
    }
    cout<<dp[N][0]<<endl;
}