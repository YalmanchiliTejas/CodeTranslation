#include<bits/stdc++.h>
using namespace std;
#define SORT(x) sort(x.begin(),x.end())
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int main(){
    string k;
    int n;
    cin>>k>>n;
    int dig=k.size();
    vector<vector<vector<ll>>> dp(dig+1,vector<vector<ll>>(n,vector<ll>(2,0)));
    //dp[桁][今までの桁和][越えたら1flag]
    dp[0][0][0]=1;
    for(int i=0;i<dig;i++){
        const int tar=k[i]-'0';
        for(int j=0;j<n;j++){
            for(int k=0;k<2;k++){
                for(int d=0;d<(k?10:(tar+1));d++){
                    dp[i+1][(j+d)%n][k||d<tar]=(dp[i+1][(j+d)%n][k||d<tar]+dp[i][j][k])%mod;
                }
            }
        }
    }
    ll ans=(dp[dig][0][0]+dp[dig][0][1]+mod-1)%mod;
    cout<<ans<<endl;
    return 0;
}
