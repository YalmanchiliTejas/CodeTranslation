#include <bits/stdc++.h>

using namespace std ;

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	int n ;
	cin>>n ;
	long long arr[n] ;
	for(int i = 0 ; i < n ; ++i)
		cin>>arr[i] ;
	long long ans = 0ll ;
	sort(arr, arr + n) ;
	while(true)
	{
		bool t = true ;
		for(int i = 0 ; i < n ; ++i)
			t &= (arr[i] < n) ;
		if(t)
			break ;
		long long now = arr[n-1] / n ;
		ans += now ;
		arr[n-1] -= now * n ;
		for(int i = 0 ; i < n-1 ; ++i)
			arr[i] += now ;
		sort(arr , arr + n) ;
	}
	return cout<<ans<<"\n" , 0 ;
}