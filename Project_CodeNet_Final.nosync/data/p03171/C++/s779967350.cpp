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
int dp[2][size][size] , a[size];
int x , n , k ;

int fun( int p , int l , int r )
{
     if( l > r ) return 0 ;

     int &ans = dp[p][l][r] ;
     if(ans !=-1) return ans ;
     if( p == 0 )
     {
        ans = max(a[l]+fun(1,l+1,r),a[r]+fun(1,l,r-1));
     }
     else 
     {
         ans = min(fun(0,l+1,r)-a[l],fun(0,l,r-1)-a[r]);
     }
     return ans ;
}

int32_t main() 
{


     /*#ifndef ONLINE_JUDGE 
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
     #endif*/
     memset(dp,-1,sizeof(dp));
     cin >> n ;
     for(int i = 0  ; i < n ; i++ ) cin >> a[i] ;
     cout<<fun(0,0,n-1)<<endl;
    return 0 ;
}
