#include <bits/stdc++.h>

using namespace std ;

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	int n ;
	cin>>n ;
	int x ;
	multiset<int>s ;
	multiset<int>::iterator it ; 
	int ans = 0 ;
	for(int i = 0 ; i < n ; ++i)
	{
		cin>>x ;
		if(s.size() == 0)
		{
			s.insert(x) ;
			ans++ ;
		}
		else
		{
			int a = *s.begin() ;
			if(a >= x)
			{
				s.insert(x) ;
				ans++ ;
			}
			else
			{
				it = s.lower_bound(x) ;
				it-- ;
				s.erase(s.find((*it))) ;
				s.insert(x) ;
 			}
		}
	}
	return cout<<ans<<"\n" , 0 ;
}