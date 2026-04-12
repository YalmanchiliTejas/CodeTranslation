/*
author : nit1n
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
int mod = 1e9 +7 ; 
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL) ;

	int n ; 
	cin >> n ; 
	vector<int> a(n) ; 
	for(int i = 0; i < n ; ++i)
		cin >> a[i] ;
	vector<int> pref(n+1, 0 ) ; 	 
	pref[n-1] = a[n-1] ; 
	for(int i = n -2 ;i >=0 ; --i)
	{
		pref[i] = pref[i +1] + a[i] ;
		pref[i] %= mod ; 
	}
	int ans = 0 ; 
	for(int i = 0; i < n ; ++i)
	{
		ans +=  a[i]*pref[i+1] ;
		ans %= mod ; 	
	}
	cout << ans ; 

}
