#include<bits/stdc++.h>
using namespace std;

const long long MOD=998244353;
int dp[3005][3005];
int arr[3005];
long long n,s;

int solve(int idx,int sum_reqd){
    if(sum_reqd==0) return n-idx+1;
    if(sum_reqd<0) return 0;
    if(idx>=n) return 0;
    if(dp[idx][sum_reqd]!=-1) return dp[idx][sum_reqd];

    int ans=(solve(idx+1,sum_reqd)+solve(idx+1,sum_reqd-arr[idx]))%MOD;
    return dp[idx][sum_reqd]=ans;
}

int main(){
    memset(dp,-1,sizeof(dp));
    cin>>n>>s;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long ans=0;
    for(int i=0;i<n;i++){
        ans=(ans+solve(i,s))%MOD;
    }
    cout<<ans<<"\n";
    
}