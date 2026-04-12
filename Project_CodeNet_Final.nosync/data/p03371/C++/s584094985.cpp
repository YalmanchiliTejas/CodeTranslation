#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	ll a, b, c, x, y;
	cin>>a>>b>>c>>x>>y;
	ll ans = a*x + b*y;
	ans = min(ans, max(x, y)*2*c);
	if(x < y){
		ans = min(ans, 2*c*x + (y - x)*b);
	}else{
		ans = min(ans, 2*c*y + (x - y)*a);
	}
	cout<<ans<<endl;

	return 0;
}