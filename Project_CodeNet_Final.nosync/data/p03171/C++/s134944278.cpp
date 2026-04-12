#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll dequeGame(int arr[], int n){

    ll dp[n][n][2];
    for(int i=0; i<n; i++){
        dp[i][i][0] = arr[i];
        dp[i][i][1] = 0;
    }
    for(int l=2; l<=n; l++){
        for(int i=0; i<=n-l; i++){
            int j = i+l-1;
            ll op1 = dp[i+1][j][1] + arr[i], op2 = dp[i][j-1][1] + arr[j];
            if(op1 > op2){
                dp[i][j][0] = op1;
                dp[i][j][1] = dp[i+1][j][0];
            }
            else{
                dp[i][j][0] = op2;
                dp[i][j][1] = dp[i][j-1][0];
            }
        }
    }
    ll ans = dp[0][n-1][0] - dp[0][n-1][1];
    return ans;
}

int main()
{
 int n;
 cin>>n;
 int arr[n];
 for(int i=0; i<n; i++)
     cin>>arr[i];
 ll ans = dequeGame(arr, n);
 cout<<ans;
 return 0;
}

