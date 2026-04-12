#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll arr[3001];
ll dp[3001][3001];

ll solve(int start,int end){
    if(start>end){
        return 0;
    }
    if(dp[start][end]!=-1){
        return dp[start][end];
    }
    ll part1=arr[start]+ min(solve(start+2,end),solve(start+1,end-1));
    ll part2= arr[end]+min(solve(start,end-2),solve(start+1,end-1));
    ll ans=max(part1,part2);
    dp[start][end]=ans;
    return ans;
}


int main(){
    int N;
    ll sum=0;
    cin>>N;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<N;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    ll final_ans=solve(0,N-1);
    ll final_diff=2*final_ans-sum;
    cout<<final_diff;
}