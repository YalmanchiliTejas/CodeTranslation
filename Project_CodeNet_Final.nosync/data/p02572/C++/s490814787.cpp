#include <bits/stdc++.h>

using namespace std ;

const long long mod = 1e9 + 7ll ;
const int MAX = 2e5 + 10 ;

long long arr[MAX] ;
int n ;

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	cin>>n ;
	long long sum = 0 ;
	for(int i = 0 ; i < n ; ++i)
	{
		cin>>arr[i] ;
		sum += arr[i] ;
	}
	sum %= mod ;
	long long ans = 0 ;
	for(int i = 0 ; i < n ; ++i)
	{
		sum = (sum - arr[i] + mod) % mod ;
		long long x = (arr[i] * sum) % mod ;
		ans = (ans + x) % mod ;
	}
	return cout<<ans<<"\n" , 0 ;
}		