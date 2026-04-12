#include <bits/stdc++.h>
#define INF (1<<30)
#define MOD 1000000007
#define l_ength size
using ll = long long;
using namespace std;

ll power(ll a, ll n){
	ll result = 1;
	ll i = 1;
	while( i <= n ) {
		if( n & i ) result *= a;
		i <<= 1ll;
		a = a * a;
	}
	return result;
}

int main(){
	ll n;
	ll x;
	cin >> n >> x;
	--x;
	ll ans = 0;
	while(n){
		if( n == 1 ){
			if( x >= 1 ) ans += 1;
			if( x >= 2 ) ans += 1;
			if( x >= 3 ) ans += 1;
			break;
		}
		ll mid = (1ll<<(n+1))-2;
		if( x == mid ) ++ans;
		if( x > mid ){
			ans += (1ll<<n);
			x -= mid;
		}
		--x;
		--n;
	}
	cout << ans << endl;
	return 0;
}