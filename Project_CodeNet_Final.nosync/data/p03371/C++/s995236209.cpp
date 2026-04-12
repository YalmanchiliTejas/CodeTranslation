#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (int)(n); i++)
#define rep2(i,x,n) for(int i = (int)x; i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define repitr(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
	int a, b, c, x, y;
	ll ans = 0;
	cin >> a >> b >> c;
	int dc = c*2;
	cin >> x >> y;
	if(dc <= a + b){
		if(x > y){
			ans += dc*y;
			if(dc <= a){
				ans += dc*(x-y);
			}else{
				ans += a*(x-y);
			}
		}else{
			ans += dc*x;
			if(dc <= b){
				ans += dc*(y-x);
			}else{
				ans += b*(y-x);
			}
		}
	}else{
		ans += a * x + b * y;
	}

	cout << ans << endl;

	return 0;
}