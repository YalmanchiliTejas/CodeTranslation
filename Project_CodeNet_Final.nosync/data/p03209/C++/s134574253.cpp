#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> ii;
typedef pair<ll, ll> pll;

int main( int argc, char *argv[] ) {
	ull n, x;
	vector<ull> patty;
	vector<ull> bsize;

	cin >> n >> x;

	patty.push_back(1);
	bsize.push_back(1);
	for ( int i = 0 ; i < 50 ; i++ ){
		patty.push_back(2 * patty[i] + 1);
		bsize.push_back(2 * bsize[i] + 3);
	}
	ll res = 0;
	while ( n > 0 ){
		if ( x == (bsize[n] + 1LL) / 2LL ){
			res += patty[n-1] + 1LL;
			n = 0;
			x = 0;
		}else if ( x > bsize[n] - n ){
			res += patty[n];
			n = 0;
			x = 0;
		}else if ( x < (bsize[n]+1LL) / 2LL ){
			x--;
			n--;
		}else{
			x -= (bsize[n]+1LL) / 2LL;
			res += 1LL + patty[n-1];
			n--;
		}
	}
	if ( n == 0 && x == 1 )
		res++;
	cout << res << "\n";

	return 0;
}
