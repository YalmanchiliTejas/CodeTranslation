#include <bits/stdc++.h>

using namespace std ; 

int main () { 
	int  t ; 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL) ;
	string s ; 
	cin >> s;  
	int fa = 0 ;
	int fb= 0 ; 
	for ( int i = 0 ; i < s.size() ; i ++ ){
		if ( s[i] == 'A' )
			fa++ ; 
		else
			fb++ ; 
	}
	if ( fa == 0 || fb == 0 )
		cout << "No" << endl ; 
	else 
		cout << "Yes" << endl ; 
}
