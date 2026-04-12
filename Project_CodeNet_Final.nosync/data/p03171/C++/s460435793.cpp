#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define endl '\n'
const int mod=1e9+7,u=3e3+5;

int n,arr[u],dp[u][u];
int solve(int low,int high){
    if(dp[low][high]==-1){
        if(low==high){
            dp[low][high]=arr[low];
        }
        else{
        	dp[low][high]=max(arr[low]-solve(low+1,high),arr[high]-solve(low,high-1));
        }
    }
    return dp[low][high];
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=-1;
        }
    }
    cout<<solve(1,n);

    return 0;
}