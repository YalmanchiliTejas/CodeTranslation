# include <bits/stdc++.h>

using namespace std ;

string a ;

int main ( )  {
	cin >> a ;
	for ( int i = 0 ; i < a.size ( ) ; ++ i )  {
		if ( a [i] == 'A' && a [i + 1] == 'C' && i != a.size ( ) - 1 )  {
			return puts ( "Yes" ), 0 ;
		}
	}
	return puts ( "No" ), 0 ;
}
