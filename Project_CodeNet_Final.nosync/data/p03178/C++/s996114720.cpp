#include <iostream>
using namespace std;
using ll = long long;
constexpr int MOD = 1e9 + 7;
 
int N;
int a[100010];
ll dp[10010][2][110];
 
int main(){
    string K;
    int D;
    cin >> K >> D;
    int N = K.size();
    dp[0][1][0] = 1;
    for(int i=0;i<N;++i){
        for(int tight=0; tight<2; ++tight){
            int x = (tight ? K[i]-'0' : 9);
            for(int j=0; j<=x; ++j){
                for(int d=0; d<=D; ++d){
                    dp[i+1][tight && x==j][(d+j)%D] += dp[i][tight][d]%MOD;
                }
            }
        }
    }
    cout << (dp[N][0][0] + dp[N][1][0] - 1)%MOD << endl;
    return 0;
}