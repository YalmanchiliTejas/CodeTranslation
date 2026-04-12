#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<iostream>
#define pb push_back
#define fi first
#define se second
#define sz(x)  x.size()
#define cl(x)  x.clear()
#define all(x)  x.begin() , x.end()
#define r(x)  scanf("%d", &x)
#define rr(x , y)  scanf("%d%d" , &x , &y)
#define rst(s)  scanf("%s" , s)
#define rl(x)  scanf("%lld" , &x)
#define rrl(x , y)  scanf("%lld%lld" , &x , &y)
#define w(x)  printf("%d" , x)
#define ww(x , y)  printf("%d %d" , x , y)
#define wl(x)  printf("%lld" , x)
#define wwl(x , y)  printf("%lld %lld" , x , y)
#define sp()  printf(" ")
#define en()  puts("")
#define rep(i , x , n)  for(int i = x ; i <= n ; i ++) 
#define per(i , n , x)  for(int i = n ; i >= x ; i --) 
#define mem0(x)  memset(x , 0 , sizeof(x))
#define mem_1(x)  memset(x , -1 , sizeof(x))
#define mem_inf(x)  memset(x , inf , sizeof(x))
#define mem__inf(x)  memset(x , -inf , sizeof(x))
#define p_queue priority_queue
#define debug(x)  printf("%d\n" , x)
#define ddebug(x , y)  printf("%d %d\n" , x , y)
using namespace std ;
//mt19937  rnd(chrono::high_resolution_clock::now().time_since_epoch().count()) ;
typedef long long ll ;
typedef unsigned long long ull ;
typedef pair<int , int> pii ;
typedef pair<ll , ll> pll ;
typedef pair<int , ll> pil ;
typedef pair<ll , int> pli ;
const int inf = 0x3f3f3f3f ;
const int maxn = 2e5 + 5 ;
const int maxm = 2e6 + 5 ;
const ll mod = 998244353 ;
int n , a[maxn] ;
map<int , ll> dp[maxn] ;
void solve()
{
	rep(i , 1 , n)  dp[i][1] = a[i] ;
	rep(i , 3 , n)
	{
		rep(j , max(2 , i / 2 - 3) , min(n , i / 2 + 3))
		{
		   ll max1 = -1e18 ; 
		   rep(k , max(1 , i - 5) , i - 2)
		   {
		  	 if(dp[k].count(j - 1) == 0)  continue ;
		  	 max1 = max(max1 , dp[k][j - 1] + a[i]) ;
		   }
		   if(max1 < -1e17)  continue ;
		   dp[i][j] = max1 ; 	
		}  
	}
	ll ans = -1e18 ;
	rep(i , max(1 , n - 10) , n)  
	  if(dp[i].count(n / 2))
        ans = max(ans , dp[i][n / 2]) ;
	wl(ans) , en() ;
}
int main()
{
	r(n) ;
	rep(i , 1 , n)  r(a[i]) ;
	solve() ;
	return 0 ;
}