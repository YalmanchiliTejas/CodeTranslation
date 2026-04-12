#include<bits/stdc++.h>
using namespace std;
long long dp[10005][101][2],mod=1000000007;
string k;
long long solve(int i,int n ,int su,bool tight,int d){
    if(i==n){
        return su==0;
    }
    if(dp[i][su][tight]!=-1)
        return dp[i][su][tight];
    int mx=(tight?k[i]-'0':9);
    long long ans=0;
    for(int j=0;j<=mx;j++){
        ans=(ans%mod+solve(i+1,n,(su+j)%d,tight&(j==mx),d)%mod)%mod;
    }
    dp[i][su][tight]=ans;
    return ans;
}

int main(){

long long d;
cin>>k;
cin>>d;

memset(dp,-1,sizeof(dp));
cout<<(solve(0,k.size(),0,1,d)-1+mod)%mod<<"\n";


}
