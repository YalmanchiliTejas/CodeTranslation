#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

const int mod = 1000000007;

int main(){
    string n;
    int k;
    cin>>n>>k;
    int len=n.size();
    vector<int[5][2]>dp(len+1);
    dp[0][0][0]=1;
    for(int i=0;i<len;i++){
        int d=n[i]-'0';
        for(int j=0;j<=k;j++){
            for(int s=0;s<=1;s++){
                for(int c=0;c<=9;c++){
                    if(s==0&&c>d)continue;
                    if(c==0){
                        if(s==0){
                            if(c<d){
                                dp[i+1][j][1]+=dp[i][j][s];
                            }else{
                                dp[i+1][j][0]+=dp[i][j][s];
                            }
                        }else{
                            dp[i+1][j][1]+=dp[i][j][s];
                        }
                    }else{
                        if(s==0){
                            if(c<d){
                                dp[i+1][j+1][1]+=dp[i][j][s];
                            }else{
                                dp[i+1][j+1][0]+=dp[i][j][s];
                            }
                        }else{
                            dp[i+1][j+1][1]+=dp[i][j][s];
                        }
                    }
                }
            }
        }
    }
    ll ans=dp[len][k][0]+dp[len][k][1];
    cout<<ans<<endl;
}