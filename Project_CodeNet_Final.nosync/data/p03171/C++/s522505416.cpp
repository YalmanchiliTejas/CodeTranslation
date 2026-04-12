#include<bits/stdc++.h>
#define int long long

using namespace std ;
int dp[3005][3005] ; 

signed main()
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ;            
	                        

	int  n   ;
	cin >> n ; 
	vector<int> a(n) ; 
	int sum = 0 ;
	for(int i = 0 ; i < n ; ++i )
	{
		cin >> a[i] ;
		sum += a[i] ; 
	}		
	for(int d =0 ; d < n ; ++d)
	{
		for(int i = 0 ; i < n-d ;++i)
		{
			int j =  i  +d ; 
			int x = ((i+2) <= j)?dp[i+2][j]:0 ; 
			int y = ((i+1) <= j-1)?dp[i+1][j-1]:0 ; 
			int z = (i <= j-2)?dp[i][j-2]:0 ; 
			dp[i][j] = max(a[i] + min(x, y) , a[j] + min(y,z)) ; 

		}
	}	
	                            
	cout <<( 2* dp[0][n-1] - sum) << endl ;
	
}
