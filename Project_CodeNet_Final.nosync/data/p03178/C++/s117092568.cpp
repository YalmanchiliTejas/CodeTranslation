#include <iostream>
#include <stdio.h>
#include <cmath>
#include <set>
#include <unordered_map>
#include <cstring>
#include <vector>

using namespace std ;

#define int long long 
#define endl "\n" 

const int N = 1e4 + 5 ;
const int M = 102 ;
const int mod = 1e9 + 7 ; 

int dp[N][M][2] , a[N] ;
int n , d ; 

int fun( int ind , int rem , int Isless)
{
     if(ind == n ) 
     {
        return (rem == 0 );
     }
     int &ans = dp[ind][rem][Isless] ;
     if(ans != -1 ) return ans ;
     ans = 0 ;
     if(Isless==0)
     {
         for(int i = 0 ; i <= a[ind] ; i ++ )
         {
             ans = ans + fun(ind+1,(rem+i)%d , (Isless|(i<a[ind])));
             ans%=mod ;
         }
     }
     else 
     {
         for( int i = 0 ; i <= 9 ; i++ )
         {
             ans =  ans + fun(ind+1,(rem+i)%d , Isless);
             ans%=mod ;
         }
     }
     return ans ;
}


int32_t main()
{
     /*#ifndef ONLINE_JUDGE 
     freopen("input.txt","r",stdin) ;
     freopen("output.txt","w",stdout) ;
     #endif*/ 
     memset(dp,-1,sizeof(dp));
     string s ;
     cin >> s >> d ;
     n = s.size() ;
     for(int i = 0 ; i< n ; i++ )
     {
         a[i] = s[i]-'0' ;
     }
     int ans = fun(0,0,0) ;
     ans -= 1 ;
     ans = (ans + mod) %mod ;
     cout<<ans<<endl;

}
