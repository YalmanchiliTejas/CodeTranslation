#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

#define Rep(i,n) for(int i = 0; i < n; ++i )
#define For(i,s,e) for(int i = s; i < e; ++i )
#define ll long long

ll N, X;
ll L[51];
ll C[51];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> X;
	L[0] = 1;
	C[0] = 1;
	For(i,1,N+1) L[i]=2*L[i-1]+3;
	For(i,1,N+1) C[i]=2*C[i-1]+1;
	ll len = L[N];
	ll t = 0;
	ll sp = 0;
	ll ep = len - 1;
	ll spx = C[N];
	ll epx = 0;
	ll p = ep;
	int k = N;
	while( true )
	{
		if( X == len - ep ){
			t = epx;
			break;
		}
		if( X == len - sp ){
			t = spx;
			break;
		}
		if( 0 == k || ep <= sp )
			break;
		ll mp = (ep+sp)/2;
		ll mpx = spx - C[--k];
		if( X == len - mp ){
			t = mpx;
			break;
		}
		else if( X < len - mp ){
			sp = mp + 1;
			spx = mpx - 1;
			ep = ep - 1;
			epx = epx + ( 0 == k ? 1 : 0 );
		}
		else{
			sp = sp + 1;
			spx = spx;
			ep = mp - 1;
			epx = mpx + ( 0 == k ? 1 : 0 );
		}
	}
	cout << t << std::endl;
}