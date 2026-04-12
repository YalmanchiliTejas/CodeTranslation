#include <bits/stdc++.h>
#define INF (1<<30)
#define MOD 1000000007
#define l_ength size
using ll = long long;
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<ll> a(n);
	for( auto &i : a ){
		cin >> i;
	}
	ll ans = 0;
	sort( a.begin(), a.end() );
	ans += abs( a[0] - a[n-1] );
	ll m = 0;
	ll M = n-1;
	for( int i = 0; i < (n/2-1); ++i ){
		ans += abs( a[M] - a[m+1] );
		ans += abs( a[m] - a[M-1] );		
		--M; ++m;
	}
	if( n % 2 == 1 ){
		ans += max( abs( a[n/2] - a[n/2+1] ), abs( a[n/2] - a[n/2-1] ) );
	}
	cout << ans << endl;
	return 0;
}