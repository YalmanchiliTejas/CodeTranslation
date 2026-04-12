#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n,m;
	while( cin >> n >> m , n || m ){
		vector<int> vc;
		vc.push_back( 0 );

		for(int i=0 ; i < n+m ; i++ ){
			int t;
			cin >> t;
			vc.push_back( t );
		}
		sort( vc.begin() , vc.end() );
		int ans = 0;
		for(int i=1 ; i < vc.size() ; i++ ){
			int d = vc[i] - vc[i-1];
			ans = max( ans , d );
		}
		cout << ans << endl;
	}
}