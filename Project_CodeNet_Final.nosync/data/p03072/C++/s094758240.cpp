#include <bits/stdc++.h>
#define INF (1<<30)
#define MOD 1000000007
#define l_ength size
using ll = long long;
using namespace std;

int main(){
	int n; cin >> n;
	vector<int> h(n);
	for( auto &k : h ) cin >> k;
	// reverse( h.begin(), h.end() );
	int m = h[0];
	int ans = 1;
	for( int i = 1; i < n; ++i ){
		if( m <= h[i] ){
			++ans;
			m = h[i];
		}
	}
	cout << ans << endl;
	return 0;
}