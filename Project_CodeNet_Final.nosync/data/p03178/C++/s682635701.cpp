#include <iostream>
using namespace std;
using ll = long long;
constexpr int MOD = 1e9 + 7;

ll dp[10010][2][110];


int main(){
    string K;
    int D;
    cin >> K >> D;
    int N = K.size();
    dp[0][0][0] = 1;
    for(int i=0;i<N;++i){
        for(int d=0; d<D; ++d){
            for(int less=0; less<2; ++less){
                int x = K[i]-'0';
                for(int j=0; j<=9; ++j){
                    if(j < x) dp[i+1][1][(d+j)%D] += dp[i][less][d] %= MOD;
                    else if(j==x) dp[i+1][less][(d+j)%D] += dp[i][less][d] %= MOD;
                    else {
                        if(less) dp[i+1][less][(d+j)%D] += dp[i][less][d] %= MOD;
                    }
                }
            }
        }
    }
    ll ans = (dp[N][0][0] + dp[N][1][0] - 1) % MOD;
    cout << ans << endl;
    return 0;
}