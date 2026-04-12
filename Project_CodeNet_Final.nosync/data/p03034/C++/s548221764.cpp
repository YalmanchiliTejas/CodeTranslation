#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007;
using ll = long long;
using namespace std;

int main(){
	int n; cin >> n;
	vector<ll> s(n);
	--n;
	ll ans = 0;
	for( auto &k : s ) cin >> k;
	for( int x = 1; x <= n; ++x ){
		ll cur = 0;
		int l = 0, r = n;
		if( n%x != 0 ){
			while( l+x < n ){
				cur += ( s[l] + s[r] );
				ans = max(ans, cur);
				l += x; r -= x;
			}

		} else {
			while( l < r ){
				cur += ( s[l] + s[r] );
				ans = max(ans, cur);
				l += x; r -= x;
			}
		}
	}
	cout << ans << endl;
}