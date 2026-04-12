//p1: max(x-y) means x should be maximum
//p2: min(x-y) means y should be maximum i.e minimize x
//sum of all array elements = x+y
//dp(i,j)->optimal value of x such that we are left with subarray (i,j)
//dp(i,j,turn) => turn=1 (p1) & turn=0(p2)
/*
dp(i,j,1) = max{
                   a[i] + dp(i+1 , j , 0),
                   a[j] + dp(i , j-1 , 0)
                }
here below a[i] will not be added as we are looking for player one score only
dp(i,j,0) = min{
                     dp(i+1 , j , 1),
                     dp(i , j-1 , 1)
                }
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[3001][3001][2];
ll solve(ll *a , ll i , ll j , ll turn){
   if(i>j){
       return 0;
   } 
   if(dp[i][j][turn] != -1){
       return dp[i][j][turn];
   }
   if(turn == 1){
       ll opt1 = a[i] + solve(a , i+1 , j , 0);
       ll opt2 = a[j] + solve(a , i , j-1 , 0);
       return dp[i][j][turn] = max(opt1 , opt2);
   }else{
       ll opt1 = solve(a , i+1 , j , 1);
       ll opt2 = solve(a , i , j-1 , 1);
       return dp[i][j][turn] = min(opt1 , opt2);
   }
}
int main() {
    ll n ;
    cin>>n;
    ll a[n+1];
    ll sum = 0;
    for(ll i=1 ; i<=n ; i++){
        cin>>a[i];
        sum += a[i];
    }
    memset(dp , -1 , sizeof(dp));
    ll scoreX = solve(a , 1 , n , 1);
    ll scoreY = sum - scoreX;
    cout<<scoreX - scoreY;
    return 0;
}
