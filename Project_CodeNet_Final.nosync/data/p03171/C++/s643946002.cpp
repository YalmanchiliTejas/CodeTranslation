#include <bits/stdc++.h>
using namespace std;

long long dp[3001][3001][2];

long long solve(vector<int> &arr, int i, int j, int turn){

    if(i>j)
        return 0;
    
    if(dp[i][j][turn] != -1)
        return dp[i][j][turn];

    if(turn == 1){
        return dp[i][j][turn] = max(arr[i] + solve(arr,i+1,j,0) , arr[j] + solve(arr,i,j-1,0));
    }
    else
        return dp[i][j][turn] = min(solve(arr,i+1,j,1) , solve(arr,i,j-1,1));
    
}

int main() {
    
    int n;
    cin>>n;

    vector<int> arr(n+1);
    memset(dp,-1,sizeof dp);

    long long sum = 0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        sum += arr[i];
    }

    long long x = solve(arr,1,n,1);
    long long y = sum - x;

    cout<<x-y;

    return 0;
}
