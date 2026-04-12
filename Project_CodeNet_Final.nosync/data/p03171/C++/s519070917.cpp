#include<bits/stdc++.h>
using namespace std;
#define ll long long 

ll dp[3001][3001];

ll fun(ll *arr, int i,int j, int&n){
    
    if(i > j) 
      return 0;
    
    if(dp[i][j] != -1){
        return dp[i][j];
    }
        
   dp[i][j] =    max((arr[i] + min(fun(arr,i+2,j,n) , fun(arr,i+1,j-1,n))),
                    (arr[j] + min(fun(arr,i+1,j-1,n), fun(arr,i,j-2,n))) );
     
    return dp[i][j];
}




void solve(){
    int n;
    cin >> n;
     ll *arr = new ll[n];
     ll sum = 0;
    for(int i=0 ;i<n; i++){
       cin >> arr[i];
       sum += arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout << 2 *fun(arr,0,n-1,n) - sum;
    return;
}
int main(){
//  #ifndef ONLINE_JUDGE
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);
// #endif 
solve();

return 0;
}