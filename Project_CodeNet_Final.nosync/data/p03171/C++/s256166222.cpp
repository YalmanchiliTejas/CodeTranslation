#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <functional>
#include <unordered_map>
#define int long long 
#define pi pair<int,int> 
#define endl "\n"
using namespace std ;

const int inf = 1e15 ;
const int size = 3005;
const int mod = 1e9 + 7 ;
int dp[2][size][size] , a[size] , n ;


int32_t main() 
{


     /*#ifndef ONLINE_JUDGE 
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
     #endif
     */
     memset(dp,-1,sizeof(dp));
     cin >> n ;
     for(int i = 1  ; i <= n ; i++ ) cin >> a[i] ;
     for(int i = 1 ;i <= n ; i++ )
     {
         dp[0][i][i] = a[i] ;
         dp[1][i][i] = -a[i] ;
     }

     for(int len = 2 ; len <= n ; len++)
     {
         for(int i = 1 ; i + len-1 <= n ; i++ )
         {
             
              int j = i+len-1;
              dp[0][i][j] = max(a[i]+dp[1][i+1][j],a[j]+dp[1][i][j-1]);
              dp[1][i][j] = min(-a[i]+dp[0][i+1][j],-a[j]+dp[0][i][j-1]);
            
         }
    }
  
    cout<<dp[0][1][n]<<endl;
    return 0 ;
}
