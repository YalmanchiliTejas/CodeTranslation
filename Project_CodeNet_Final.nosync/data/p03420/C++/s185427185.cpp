#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
	ll n, k;
	cin >> n >> k;
	ll ans = 0;
	if(k == 0){
		cout << n * n << endl;
		return 0;
	}
	for(ll b = k+1; b < n+1; b++){
		ll add = 0;
		add = (n+1)/b * (b-k);
		ll temp = (n+1) -  (n+1)/b*b;
		if(temp > k) add += (temp - k);
		// cerr << b << " " << add << endl;
		ans += add;
	}
	cout << ans << endl;
	return 0;
}