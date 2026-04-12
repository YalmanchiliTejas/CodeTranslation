#include<iostream>
#include<string>

using namespace std;

const long long MOD=1000000007;

string s;
long long n,dp[2][110][10010]={0};

signed main(){
    cin>>s>>n;
    dp[0][0][0]=0;
    dp[1][0][0]=1;
    for(int i=0;i<s.length();++i){
        for(int j=0;j<n;++j){
            for(int k=0;k<=9;++k){
                (dp[0][(j+k)%n][i+1]+=dp[0][j][i])%=MOD;
            }
            for(int k=0;k<s[i]-'0';++k){
                (dp[0][(j+k)%n][i+1]+=dp[1][j][i])%=MOD;
            }
            (dp[1][(j+s[i]-'0')%n][i+1]+=dp[1][j][i])%=MOD;
        }
    }

    cout<<(dp[0][0][s.length()]-1+dp[1][0][s.length()]+MOD)%MOD<<endl;

    return 0;
}