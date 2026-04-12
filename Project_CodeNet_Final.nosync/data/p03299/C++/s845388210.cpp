#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int MN = 110;
const ll M = 1e9+7;
inline ll mul(ll a, ll b) {return (a*b)%M;}
ll bp(ll b, ll p) {
	ll ac = 1;
	while(p) {
		if(p&1) {
			ac = mul(b,ac);
		}
		b = mul(b,b);
		p >>= 1;
	}
	return ac;
}
inline ll norm(ll val) {
	return (val<0)?val%M+M:val%M;
}
ll dp[MN][MN];
ll hc[MN][MN];
ll va[MN];
ll w[MN],wa[MN];
ll lim[MN],rs[MN][MN];
ll n;
ll ds(ll r, ll h) {
	if(r >= n-1) {return 1;}
	if(dp[r][h] != -1) {
		return dp[r][h];
	}
	if(h > wa[r]) {
		return dp[r][h] = ds(r,wa[r]);
	}
	if(wa[r] == 0) {
		return dp[r][h] = ds(r+1,0);
	}
	ll hv = 0;
	if(h == wa[r]) {
		hv = 0;
	} else {
		hv = 0;
		for(int i=h;i<wa[r];i++) {
			ll sz = va[i+1];
			ll ot = hc[r][i+1]-sz;
			hv += mul(mul(norm(bp(2,sz)-1),bp(2,ot)),ds(rs[r][i+1],wa[r]));
		}
	}
	ll vv = ds(r+1,max(wa[r],h));
	ll ev = ds(r+1,wa[r]);
	return dp[r][h] = norm(hv+vv+ev);
}
int main() {
	cin >> n;
	memset(lim,-1,sizeof(lim));
	memset(dp,-1,sizeof(dp));
	memset(hc,0,sizeof(hc));
	for(int i=0;i<n;i++) {
		cin >> w[i];
	}
	if(n == 1) {
		cout << bp(2,w[0]) << '\n';
		return 0;
	}
	ll los = 0;
	for(int i=0;i<n-1;i++) {
		wa[i] = min(w[i],w[i+1]);
		lim[i] = max(lim[i],wa[i]);
		lim[i+1] = max(lim[i+1],wa[i]);
		wa[i]--;
	}
	for(int i=0;i<n;i++) {
		if(lim[i] == 1) {lim[i] = 0;}
		los += w[i]-lim[i];
	}
	set<ll> bs;
	for(int i=0;i<n-1;i++) {
		bs.insert(wa[i]);
	}
	bs.insert(0);
	ll lst = 0;
	ll ctr = 0;
	map<ll,ll> mo;
	for(auto& it: bs) {
		mo[it] = ctr;
		va[ctr] = it-lst;
		ctr++;
		lst = it;
	}
	for(int i=0;i<n-1;i++) {
		wa[i] = mo[wa[i]];
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<n-1;j++) {
			int r = j;
			while(r < n-1 && wa[r] >= i) {
				r++;
			}
			rs[j][i] = r;
		}
	}
	for(int i=1;i<n;i++) {
		for(int j=0;j<n-1;j++) {
			for(int k=i;k<n;k++) {
				for(int l=j;l<rs[j][i];l++) {
					if((l <= j || wa[l-1] < k) && wa[l] >= k) {
						hc[j][i] += va[k];
					}
				}
			}
		}
	}
	ll res = ds(0,0);
	int x = 0;
	while(x < n-1) {
		if(rs[x][1] == x) {
			x++;
		} else {
			res = mul(res,2);
			x = rs[x][1];
		}
	}
	res = mul(res,bp(2,los));
	cout << res << '\n';
}
