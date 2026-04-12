//              +-- -- --++-- +-In the name of ALLAH-+ --++-- -- --+              \\

#include <bits/stdc++.h>

#define F first
#define S second
#define _sz(x) (int)x.size()

using namespace std ;
using ll = long long ;
using ld = long double ;
using pii = pair <int , int> ;

int const N = 10 ;
int n , m ;
string s[N] ;

void err () {
	cout << "Impossible\n" ;
	exit(0) ;
}

void go (int x , int y) {
	s[x][y] = '.' ;

	if (x == n - 1 && y == m - 1) return ;

	if (x == n - 1) {
		if (s[x][y + 1] != '#') err() ;
		go(x , y + 1) ;
	}
	else if (y == m - 1) {
		if (s[x + 1][y] != '#') err() ;
		go(x + 1 , y) ;
	}
	else {
		if (s[x + 1][y] == '#') go(x + 1 , y) ;
		else if (s[x][y + 1] == '#') go(x , y + 1) ;
		else err() ;
	}
}

int main(){
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) ;

	cin >> n >> m ;
	for (int i = 0 ; i < n ; i ++) cin >> s[i] ;

	go(0 , 0) ;

	for (int i = 0 ; i < n ; i ++)
		for (int j = 0 ; j < m ; j ++)
			if (s[i][j] == '#') err() ;

	cout << "Possible\n" ;
}