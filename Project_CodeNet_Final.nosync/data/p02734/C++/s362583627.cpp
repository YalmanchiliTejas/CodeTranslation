#include <iostream>
#define MOD 998244353
using namespace std;
typedef long long ll;
ll dp[3001][3001],n,s,a,ans;
int main(void){
    cin>>n>>s;
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        cin>>a;
        for(int j=0;j<s;j++){
            dp[i+1][j]+=dp[i][j];
            dp[i+1][j]%=MOD;
            if(a+j<=s&&j==0)dp[i+1][a+j]+=i+1;
            else if(a+j<=s&&dp[i][j]>0)dp[i+1][a+j]+=dp[i][j];
            dp[i+1][a+j]%=MOD;
        }
        ans+=dp[i+1][s]*(n-i)%MOD;
        ans%=MOD;
    }
    cout<<ans<<endl;
}
