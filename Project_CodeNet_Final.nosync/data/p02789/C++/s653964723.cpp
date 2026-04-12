# include <bits/stdc++.h>
# define FILE
using namespace std;

int main(){

	# ifdef FILEs
		freopen( "input.txt", "r", stdin );
		freopen( "output.txt", "w", stdout );
	# endif
	ios_base::sync_with_stdio( false );
	int n, m;
	cin >> n >> m;
	if( n > m ){
		cout << "No";
	}else{
		cout << "Yes";
	}
}