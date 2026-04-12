#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[3005][3005];
ll solve(int s,int e,vector<ll>&arr){
    
    if(s==e)return arr[s];
    if(dp[s][e]!=-1)return dp[s][e];
    return dp[s][e]=max(arr[e]-solve(s,e-1,arr),arr[s]-solve(s+1,e,arr));
    
}

int main(){
    int n;
    cin>>n;
    vector<ll> arr(n);
    for(ll &i : arr){
        cin>>i;
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=-1;
        }
    }
    cout<<solve(0,n-1,arr)<<endl;
}