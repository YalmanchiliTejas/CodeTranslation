#include<bits/stdc++.h>
using namespace std;

#define int long long

int max(int a,int b){
    return (a>b?a:b);
}
const int N = 3005;
int dp[N][N];
int n, arr[N];
int32_t main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    for(int i = n;i>0;i--){
        for(int j=i;j<=n;j++){
            dp[i][j] = max(arr[i]-dp[i+1][j],arr[j]-dp[i][j-1]);
        }
    }
    cout<<dp[1][n]<<endl;
}