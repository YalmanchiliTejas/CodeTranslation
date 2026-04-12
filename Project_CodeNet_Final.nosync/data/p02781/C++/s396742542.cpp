#include <bits/stdc++.h>
using namespace std;

#define int long long
string S;
int const M = 101;
int dp[M][5][2], K, D, N;
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> S; cin >> K;
    N = S.size();
    dp[N][K][0] = dp[N][K][1] = 1;
    for(int i = N - 1; i >= 0; i--){
        for(int k = K; k >= 0; k--, D = S[i] - '0'){
            for(int d = 1; d >= 0; d--){
                for(int j = (d) ? D : 9; j >= 0; j--){
                    dp[i][k][d] += dp[i + 1][min(4ll,k + (j > 0))][d & (j == D)];
                }
            }
        }
    }
    cout << dp[0][0][1] << endl;
    return 0;
}
