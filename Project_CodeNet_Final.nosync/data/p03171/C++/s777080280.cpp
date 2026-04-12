#include <bits/stdc++.h>
#define int long long
int dp[3001][3001];

using namespace std;

int solve(int i,int j,int *arr){
    if(i>j) return 0;
    if(i==j) return dp[i][j] = arr[i];
    if(dp[i][j]!=-1) return dp[i][j];


    int a = solve(i+2,j,arr);
    int b = solve(i+1,j-1,arr);
    int c = solve(i,j-2,arr);

    int ans = max(min(arr[i] - (arr[i+1] - a),arr[i] - (arr[j]-b)) , min(arr[j] - (arr[j-1] - c),arr[j] - (arr[i]-b)));
    return dp[i][j] = ans;

}




int32_t main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=  0 ;i < n ; i++) cin >> arr[i];

    for(int i =0 ; i < 3001;i++){
        for(int j= 0 ; j < 3001;j++) dp[i][j] = -1;
    }

    solve(0,n-1,arr);
    cout << dp[0][n-1];


}
