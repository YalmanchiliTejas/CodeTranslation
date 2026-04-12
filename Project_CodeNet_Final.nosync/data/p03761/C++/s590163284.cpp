#include <bits/stdc++.h>

using namespace std ; 

int main () { 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL) ; 
	
	int n ; 
	vector <string> s ; 
	cin >> n ; 
	while ( n-- ) {
		string a ; 
		cin >> a ; 
		s.push_back(a) ; 
	}
	int arr[26] ; 
	for ( int i = 'a' ; i <= 'z' ; i ++ ) { 
		char c = i ;
		int minimum = 51 ; 
	for ( auto & str : s ) {
		int x=  count(str.begin(),str.end(),c);
		minimum = minimum < x  ? minimum : x ;
	}
	arr[i-'a'] = minimum ; 
}
	for ( int i = 0 ; i < 26 ; i ++ ) {
		if ( arr[i] != 0 ) {
			for ( int j = 0 ; j < arr[i] ; j ++ ) {
				cout << char(i +'a') ;
			}
		}
	}
}
