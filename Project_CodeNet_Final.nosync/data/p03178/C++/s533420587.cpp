#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1e9+7;
int main(void){
    string K;
    int D;
    cin>>K>>D;
    int n=K.size();
    ll dp[10010][2][100]={};
    dp[0][0][0]=1;
    for(int i=0;i<n;i++){
        int a=K[i]-'0';
        for(int j=0;j<D;j++){
            for(int x=0;x<10;x++){
                dp[i+1][1][(j+x)%D]+=dp[i][1][j];
                if(x==a){
                    dp[i+1][0][(j+x)%D]+=dp[i][0][j];
                }
                else if(x<a){
                    dp[i+1][1][(j+x)%D]+=dp[i][0][j];
                }
                dp[i+1][0][(j+x)%D]%=mod;
                dp[i+1][1][(j+x)%D]%=mod;
            }
        }
    }
    cout<<(dp[n][0][0]+dp[n][1][0]-1+mod)%mod<<endl;
}