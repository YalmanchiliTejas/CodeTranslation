//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
typedef pair<int,int> pii; 

const int maxN = 8 + 1; 

string a[maxN]; 

int main() { 
	ios::sync_with_stdio(false); cin.tie(0); 
	int n,m; cin >> n >> m ;
	int v = n + m - 2; 
	int cnt = 0; 
	for( int i = 0 ;i< n ; i++ ) { 
		cin >> a[i];
		for( int j = 0 ; j < m ; j++ ) 
			cnt += a[i][j] == '#' ; 
	}

	bool canDo = false; 
	if( cnt == n + m - 1 && a[0][0] == '#' ) 
		for( int mask = 0 ; mask < (1<<v) ; mask++ ) 
			if( __builtin_popcount( mask ) == n - 1 ) { 
				bool good = true;
				int i=0,j=0; 
				for( int k = 0 ; k < v ; k++ ) { 
					if( (mask>>k) & 1 ) 
						i++; 
					else
						j++; 
					if( a[i][j] != '#' ) good = false; 
				}
				canDo |= good; 
			}
	if( canDo ) cout << "Possible" << endl;
	else cout << "Impossible" << endl;
}

