#include<bits/stdc++.h>
#define mod 1000000007
using namespace std; 
int main(){
    string k;
    int d;
    cin>>k>>d;
    //dp[i][j][k] represents how many numbers with i digits have
    //their sum of digits modulo d equal to j and whether the 
    //bound on the ith digit is tight or not, if it's not tight
    //the current digit can take numbers from 0 to 9 else it 
    //can digits only from 0 to k[i]
    int dp[k.size()+1][d][2];  
    memset(dp,0,(k.size()+1)*d*sizeof(dp[0][0]));
    dp[0][0][0] = 1;
    dp[0][0][1] = 0;
    for(int i=1;i<=k.size();i++){
        for(int j=0;j<d;j++){
            for(int l=0;l<=9;l++){
                dp[i][(j+l)%d][1]=(dp[i][(j+l)%d][1]+dp[i-1][j][1])%mod;
                if(l<k[i-1]-'0')
                    dp[i][(j+l)%d][1]=(dp[i][(j+l)%d][1]+dp[i-1][j][0])%mod;
                
            }
            dp[i][(j+(k[i-1]-'0'))%d][0]=(dp[i][(j+(k[i-1]-'0'))%d][0]+dp[i-1][j][0])%mod;
        }
    }
    // cout<<dp[k.size()][0][0]<<" "<<dp[k.size()][0][1]<<"\n";
    int ans = (dp[k.size()][0][0]+dp[k.size()][0][1]-1+mod)%mod;
    cout<<ans<<"\n";
    return 0;
}