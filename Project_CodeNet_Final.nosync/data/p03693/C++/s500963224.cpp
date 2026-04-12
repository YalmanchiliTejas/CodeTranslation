#include <bits/stdc++.h>

using namespace std ;

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	int n , x , y;
	cin>>n>>x>>y ;
	int a = (n*10+x)*10+y ;
	return cout<<(a%4 == 0 ? "YES" : "NO") , 0 ;
}