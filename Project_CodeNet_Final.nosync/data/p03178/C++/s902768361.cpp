#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
constexpr int MOD = 1e9 + 7;

ll dp[10010][2][110];

int main(void){
    string K;
    int D;
    cin >> K >> D;
    int N = K.size();
    dp[0][0][0] = 1;
    for(int n=0;n<N;++n){
        for(int d=0;d<D;++d){
            for(int free=0;free<2;++free){
                int x = K[n] - '0';
                for(int i=0;i<=9;++i){
                    if(i<x) dp[n+1][1][(d+i)%D] += dp[n][free][d] %= MOD;
                    else if(i==x) dp[n+1][free][(d+i)%D] += dp[n][free][d] %= MOD;
                    else if(free) dp[n+1][free][(d+i)%D] += dp[n][free][d] %= MOD;
                }
            }
        }
    }
    ll ans = (dp[N][0][0] + dp[N][1][0] - 1)%MOD;
    cout << ans << endl;
    return 0;
}