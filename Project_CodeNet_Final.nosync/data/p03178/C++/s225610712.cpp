#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1e9+7;
int main(void){
    string K;
    int D;
    cin>>K>>D;
    int n=K.size();
    ll dp[10001][2][100]={};//dp[上から何桁目まで決めたか][未満フラグ][各桁の和をDで割った余り]
    dp[0][0][0]=1;//初期条件
    for(int i=0;i<n;i++){
        int a=K[i]-'0';
        for(int j=0;j<D;j++){
            for(int x=0;x<10;x++){
                dp[i+1][1][(j+x)%D]+=dp[i][1][j];//i桁目までの段階でK未満確定→(i+1)桁目までの段階でK未満確定
                if(x==a){
                    dp[i+1][0][(j+x)%D]+=dp[i][0][j];//i桁目まで一致→(i+1)桁目まで一致
                }
                else if(x<a){
                    dp[i+1][1][(j+x)%D]+=dp[i][0][j];//i桁目まで一致→(i+1)桁目の段階でK未満確定
                }
                dp[i+1][0][(j+x)%D]%=mod;
                dp[i+1][1][(j+x)%D]%=mod;
            }
        }
    }
    cout<<(dp[n][0][0]+dp[n][1][0]-1+mod)%mod<<endl;//dpでは「0」も数えられているのでそれを引く
}