#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) {}
#endif

ll bs[51]; // size
ll bp[51]; // num of p

ll f( ll n, ll x ){
	if ( x >= bs[n] )
		return bp[n];
	if ( x <= 0 ) return 0;
	
	ll count = 0;
	x--;
	count += f( n-1, x ); x -= bs[n-1];
	if ( x > 0 ) count++;
	x--;
	count += f( n-1, x ); x -= bs[n-1];
	x--;
	return count;
}



int main(){
	ll n, x;
	cin >> n >> x;
	
	ll s = 1;
	ll p = 1;
	rep(i,51){
		bs[i] = s;
		bp[i] = p;
		s = 3 + s*2;
		p = 1 + p*2;
		eprintf( "%d %lld %lld\n", i, bs[i], bp[i] );
	}
	
	cout << f(n,x) << endl;
	
	return 0;
}


