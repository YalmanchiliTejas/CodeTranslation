#include<bits/stdc++.h>
#define mod 1000000007
#define N 10001
#define D 100
int dp[N][D][2];
//dp[i][j][k] tells us number of ways to get numbers from 0 to first 
// i digits of the given number having sum of digits as j under
// modulo d when the ith digit is tightly bounded (for k=1) or
// not bounded (for k=0)
using namespace std; 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string k;
    int d;
    cin>>k>>d;
    reverse(k.begin(),k.end());
    memset(dp,0,(k.size()+1)*d*sizeof(dp[0][0]));
    dp[0][0][0] = 1;
    dp[0][0][1] = 1;
    for(int i=1;i<=k.size();i++){
        for(int j=0;j<d;j++){
            for(int m=0;m<2;m++){
                int lim = (m==0)?9:(k[i-1]-'0');
                for(int l=0;l<=lim;l++){
                    int prevm = m;
                    if(l<(k[i-1]-'0'))prevm=0;
                    dp[i][j][m] = (dp[i][j][m]+dp[i-1][(j+l)%d][prevm])%mod;
                }
            }
        }
    }
    int ans = (dp[k.size()][0][1]-1+mod)%mod;
    cout<<ans<<"\n";
    return 0;
}