#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1e9+7;
const int INF=1e9;
const ll LINF=(ll)1e18;

int main(){
    string s;
    int k;
    cin>>s>>k;
    int num=s.size();
    ll dp[num+1][2][k+2];
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=1;
    for(int i=0;i<num;i++){
        int D=s[i]-'0';
        for(int j=0;j<2;j++){
            for(int l=0;l<=k;l++){
                for(int d=0;d<=(j?9:D);++d){
                    if(d!=0)dp[i+1][j||(d<D)][l+1]+=dp[i][j][l];
                    else dp[i+1][j||(d<D)][l]+=dp[i][j][l];
                }
            }
        }
    }
    cout<<dp[num][0][k]+dp[num][1][k]<<endl;
}
