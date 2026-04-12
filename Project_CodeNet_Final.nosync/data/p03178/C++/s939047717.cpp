#include<bits/stdc++.h>
#define mod 1000000007
using namespace std; 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
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
            for(int m=0;m<2;m++){
                for(int l=0;l<=9;l++){
                    if(l>(k[i-1]-'0')&&!m)break;
                    dp[i][(j+l)%d][m||(l<(k[i-1]-'0'))]=(dp[i][(j+l)%d][m||(l<(k[i-1]-'0'))]+dp[i-1][j][m])%mod;
                    
                }
            }
        }
    }
    int ans = (dp[k.size()][0][0]+dp[k.size()][0][1]-1+mod)%mod;
    cout<<ans<<"\n";
    return 0;
}