#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

ll fc(int lv){
	ll ans = 1;
	rep(i, lv){
		ans = ans * 2 + 3;
	}
	return ans;
}

ll al(ll lv){
	ll ans = 1;
	rep(i, lv){
		ans = ans * 2 + 1;
	}
	return ans;
}

ll b_s(ll x, ll l, ll r, int lv){
	if(lv == 0){
			return 1;
	}
	ll mid = (l+r)/2;
	if(x == r-1) return al(lv-1) * 2 + 1;
	else if(x == l) return 0;
	else if(mid < x) return b_s(x, mid + 1, r-1, lv-1) + al(lv-1) + 1;
	else if(mid == x) return al(lv-1) + 1;
	else return b_s(x, l+1, mid, lv-1);
}

int main(){
	int n;
	ll x;
	cin >> n >> x;
	ll count = fc(n);
	ll ans = b_s(x-1, 0, count, n);
	cout << ans << endl;
	return 0;
}