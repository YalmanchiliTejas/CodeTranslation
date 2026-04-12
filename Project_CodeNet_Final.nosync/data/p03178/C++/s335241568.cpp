#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=21;

int main(){
    
    string K;cin>>K;
    int D;cin>>D;
    ll dp[2][K.size()+1][D];//1個目=0のときは確実にK以下、=1のときはわからん 2個目は上から何桁(1スタート) 3個目はあまり(0~D-1)
    for(int i=0;i<2;i++){
        for(int j=0;j<K.size()+1;j++){
            for(int k=0;k<D;k++){
                dp[i][j][k]=0;
            }
        }
    }
    dp[1][0][0]=1;
    
    for(int j=0;j<K.size();j++){
        for(int k=0;k<D;k++){
            for(int l=0;l<10;l++){
                dp[0][j+1][(k+l)%D]=(dp[0][j+1][(k+l)%D]+dp[0][j][k])%mod;
            }
        }
        for(int k=0;k<D;k++){
            for(int l=0;l<K[j]-'0';l++){
                dp[0][j+1][(k+l)%D]=(dp[0][j+1][(k+l)%D]+dp[1][j][k])%mod;
            }
            dp[1][j+1][(k+(K[j]-'0'))%D]=(dp[1][j+1][(k+(K[j]-'0'))%D]+dp[1][j][k])%mod;
        }
    }
    cout<<(dp[0][K.size()][0]+dp[1][K.size()][0]+mod-1)%mod<<endl;
}
