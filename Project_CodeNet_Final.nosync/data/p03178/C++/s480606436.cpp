#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
int solve(string k,int dp[][100][2],int D,int pos,int d,int tight){
    if(dp[pos][d][tight]!=-1){
        return dp[pos][d][tight];
    }
    int ub;
    if(tight){
        ub=k[pos]-'0';
    }
    else{
        ub=9;
    }
    //base case
    if(pos==k.length()-1){
        int ans=0;
        for(int x=0;x<=ub;x++){
            if(x%D==d){
                ans++;
            }
        }
        return ans;
    }
    //recursive call
    int ans=0;
    for(int x=0;x<=ub;x++){
        ans=(ans+solve(k,dp,D,pos+1,(d-x%D+D)%D,tight&(x==ub)))%mod;
    }
    return dp[pos][d][tight]=ans;
}
int32_t main(){
    string k;
    cin>>k;
    int D;
    cin>>D;
    int n=k.length();
    int dp[n][100][2];
    for(int i=0;i<n;i++){
        for(int j=0;j<100;j++){
            for(int k=0;k<2;k++){
                dp[i][j][k]=-1;
            }
        }
    }
    //excluding 0 because we have to count number between 1 to K
    cout<<(solve(k,dp,D,0,0,1)-1+mod)%mod;
    return 0;
}
