#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll arr[3000];
ll dp[3000][3000][2];
int n;
ll X=0,Y=0;

ll solve(int s, int e, int turn){
    
    if(s>e){
        return 0;//max(arr[s],arr[e]);
    }
    if(dp[s][e][turn]!=-1)
        return dp[s][e][turn];

    if(turn ==1 ){
        return dp[s][e][turn]=max(arr[s]+solve(s+1,e,0),arr[e]+solve(s,e-1,0));
    }else
    {
        return dp[s][e][turn]=min(solve(s+1,e,1),solve(s,e-1,1));
    }
}

int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>n;
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
        //cout<<sum<<endl;
    }
    ll x=solve(0,n-1,1);
    cout<<x-(sum-x);
    return 0;
}