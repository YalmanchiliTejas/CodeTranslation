#include <bits/stdc++.h>

using namespace std;
typedef long long ll ;
#define rep(i,a,n) for(int i=a ; i<n ; i++)
#define pb push_back

int main()
{
	int T=1;
	// cin >> T ;

	while(T--)
	{
		int n ;
		cin>>n ;
		ll a[n] ;
		rep(i,0,n) cin>>a[i] ;

		ll dp[n][n] ;

		rep(i,0,n) dp[0][i]=a[i] ;

		rep(i,1,n)
		{
			int l=i+1 ;
			rep(j,0,n-l+1)
				dp[i][j] = max(a[j]-dp[i-1][j+1] , a[j+l-1]-dp[i-1][j]) ;
		} 
		cout<<dp[n-1][0]<<endl ;
	}
	return 0;
}