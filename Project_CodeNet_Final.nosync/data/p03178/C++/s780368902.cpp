#include<bits/stdc++.h>
using namespace std;

static const int MOD=1e9+7;

int main(){
    string K; cin >> K;
    int D; cin >> D;

    int N=K.size();
    long long dp[N+1][2][D+1]; //dp[桁数][上限ギリギリかどうか][Dで割ったあまり]
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=1;
    for(int i=0;i<N;i++){
        int s=K[i]-'0';
        for(int k=0;k<D;k++){
            for(int j=0;j<2;j++){
                for(int d=0;d<=(j?9:s);d++){
                    dp[i+1][j||(d<s)][(k+d)%D]+=dp[i][j][k%D]%MOD;
                    dp[i+1][j||(d<s)][(k+d)%D]%=MOD;
                }
            }
        }
    }
    long long ans=((dp[N][0][0]+dp[N][1][0])%MOD+MOD-1)%MOD;
    cout << ans << endl;
}