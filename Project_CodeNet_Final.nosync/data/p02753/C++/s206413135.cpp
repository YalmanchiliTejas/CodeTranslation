# include <bits/stdc++.h>

# define pb push_back
# define ll long long

using namespace std;

ll z , o ;

	
int main() {

	string s ;
	cin >> s ;
	if( ( s[0] == s[1] && s[0] != s[2] ) || ( s[0] == s[2] && s[0] != s[1] ) || ( s[1] == s[2] && s[0] != s[1]) ){
		cout << "Yes" << endl ;
	}
	else{
		cout << "No" << endl ;
	}

}
