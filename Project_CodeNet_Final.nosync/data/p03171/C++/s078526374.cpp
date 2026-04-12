#include <bits/stdc++.h>
using namespace std;
#define int long long
int arr[3001];
int dp[3001][3001];

int f(int s, int e){
    if(s>e) return 0;
    int &ans = dp[s][e];
    if(ans!=-1) return ans;
    
    ans = max(arr[s]+min(f(s+2,e), f(s+1,e-1)),arr[e]+min(f(s,e-2), f(s+1,e-1)));
    return ans;
}

int32_t main(){
    memset(dp,-1,sizeof(dp));
    int n;    
    cin>>n;
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    int temp = f(0,n-1);
    cout<<temp-(sum-temp);
}