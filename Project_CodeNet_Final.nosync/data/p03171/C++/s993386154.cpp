#include <bits/stdc++.h>
#define l_ength size
using ll = long long;
const int mod = 1000000007;
const ll infll = (1ll<<60);
using namespace std;

const int bound = 3210;
int n;

// dp(p, q) := 半開区間 [p, q) において X-Y の最大値
ll d[bound][bound];
ll a[bound];
bool bscht[bound][bound];

ll dp( int p, int q ){
	if( p == q ) return 0;
	if( bscht[p][q] ) return d[p][q];
	else bscht[p][q] = true;
	// first
	if( (n+q-p)%2 == 0 ){
		return d[p][q] = max( dp(p+1, q)+a[p], dp(p, q-1)+a[q-1] );
	}
	// second
	else {
		return d[p][q] = min( dp(p+1, q)-a[p], dp(p, q-1)-a[q-1] );
	}
}

int main(){
	cin >> n;
	for( int i = 0; i < n; ++i ) cin >> a[i];
	cout << dp(0, n) << endl;
	/*
	for( int p = 0; p <= n; ++p ){
		for( int q = p+1; q <= n; ++q ){
			cout << "[" << p << ", " << q << "): " << dp(p, q) << endl;
		}
	}
	*/
}