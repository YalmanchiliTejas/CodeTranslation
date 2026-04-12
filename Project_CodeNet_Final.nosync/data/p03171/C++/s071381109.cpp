#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 3090 ,OO = 1e9;
ll a[N] , n , dp[N][N] , sum;
ll Dp(int i , int j){

if(i>j){

    return 0;
}
ll &ret = dp[i][j];
if(ret != -1) return ret;
ret=0;
ret = max(a[i] - Dp(i+1 , j)  , a[j] - Dp(i , j-1));

return ret;
}
int main()
{
    cin >> n;
    for(int i=0;i<n;i++){

        cin >> a[i] , sum+=a[i];
    }
    memset(dp , -1 , sizeof dp);
    cout << Dp(0 , n-1);
    return 0;
}
