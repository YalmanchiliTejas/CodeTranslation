#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    vector<vector<ll>> dp(N+100, vector<ll>(N+100));
    for(int width = 1;width <= N; width++){
        for(int l = 0;l < N; l++){
            int r = l + width;
            if(r > N) continue;
            if((N&1) ^ (width&1)){
                // 後攻
                dp[l][r] = min(dp[l+1][r] - A[l], dp[l][r-1] - A[r-1]);
            }else{
                // 先行
                dp[l][r] = max(dp[l+1][r] + A[l], dp[l][r-1] + A[r-1]);
            }
        }
    }
    cout << dp[0][N] << endl;
    return 0;
}
