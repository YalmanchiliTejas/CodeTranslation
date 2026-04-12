#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll a, b, c, x, y, res;
	cin>>a>>b>>c>>x>>y;
	res = numeric_limits<ll>::max() - 1;
	if(x <= y){
		for(int i = 0; i <= x; ++i){
			ll ap = (i * a) + (i * b) + ((y - i) * 2 * c);
			ll bp = (i * 2 * c) + (x - i) * a + (y - i) * b;
			res = min(res, min(ap,  bp));
		}
	}
	else{
		for(int i = 0; i <= y; ++i){
			ll ap = (i * b) + ((x - i) * 2 * c) + (i * a);
			ll bp = (i * 2 * c) + (x - i) * a + (y - i) * b;
			res = min(res, min(ap,  bp));
		}
	}
	if(2 * max(x, y) * c < res){
		res = 2 * max(x, y) * c;
	}
	cout<<res<<endl;
	return 0;
}
