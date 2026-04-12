#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	ll cost1 = 2 * max(x,y) * c; // Buy all from c
	cost1 = min( cost1, a * x + b * y ); // Buy all individual
	ll mx = min(x,y);
	if( mx == x ){
		ll cst2 = mx * 2 * c + (y-mx) * b;
		cost1 = min(cost1, cst2);
	}
	if( mx == y ){
		ll cst2 = mx * 2 * c + (x-mx) * a;
		cost1 = min(cost1, cst2);
	}
	cout<<cost1<<endl;

	return 0;
}
