#include <bits/stdc++.h>
using namespace std;

long long int rec(int* arr, int i, int j, vector<vector<long long int>>& dp, vector<vector<bool>>& vis){
    if(vis[i][j])
        return dp[i][j];
    vis[i][j]=1;
    if(i==j) return dp[i][j] = arr[i];
    return dp[i][j] = max(arr[i]-rec(arr,i+1,j,dp,vis),arr[j]-rec(arr,i,j-1,dp,vis));
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<vector<long long int>> dp(n+1, vector<long long int>(n+1, -1));
    vector<vector<bool>> vis(n+1, vector<bool>(n+1, false));
    cout<<rec(arr,0,n-1,dp,vis)<<"\n";
}