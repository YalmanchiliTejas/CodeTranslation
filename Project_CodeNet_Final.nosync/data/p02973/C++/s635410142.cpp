/*
    ____        __
   / __ \____  / /_  ____ _____ ___
  / /_/ / __ \/ __ \/ __ `/ __ `__ \
 / _, _/ /_/ / / / / /_/ / / / / / /
/_/ |_|\____/_/ /_/\__,_/_/ /_/ /_/
*/
#include<bits/stdc++.h>

typedef long long ll ;

#define X   first
#define Y   second
#define mp  make_pair
#define pii pair<int , int>
#define vec vector
#define vpii vector<pair<int , int>>
#define i_n   int i = 0 ; i< n ; i++
#define cn  int n ; cin>>n
#define file_io freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define cina int a[n] ; for(int i = 0 ; i < n ; i++) cin>>a[i]
#define pb push_back
#define SZ(x) ll(x.size())

using namespace std;
const int maxn = 1000*100+5 ;
int n , a[maxn] , last[maxn] , dp[maxn] ; 
int main()
{
	migmig ;
	
	cin>>n ; 
	for(int i = 1 ; i <= n ; i ++)
	{
		cin>>a[i] ; 
	}
	int ans = 0 ; 
	fill(last , last + maxn , -1) ; 
	for(int i = 1 ; i <= n ; i++)
	{
		int l = 1 , r = 100004 ; 
		while(r - l > 1)
		{
			int mid = (l + r) / 2 ; 
			if(last[mid] >= a[i]) l = mid ; 
			else r = mid ; 
			 
		}
		ans = max(ans , l+1) ; 
		
		last[l+1] = max(last[l+1] , a[i]) ; 
	}
	cout<<ans-1; 
//	cout<<endl ; 
//	for(int i = 0 ; i <= n ; i++) cout<<last[i]<<" " ; 

}
//////
////////
///////////

