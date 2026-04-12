#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	ll n;
	ll x, m;
	cin >> n >> x >> m;
	map<ll,ll> mp;
	vector<ll> a,ind(m+1);
	ll cnt=0;
	ll ai = x;
	mp[ai]++;
	a.push_back(ai);
	ind[ai]=cnt;
	ll st=0, ed=n-1;
	bool circlep = false;
	for(ll i=2; i < n+1;i++) {
		ll now = ll(ai*ai) % m;
		if (mp[now]==1){
			// now 既出
			circlep = true;
			ed = cnt;
			st = ind[now];
			break;
		} else if (now == 0) {
			ed = cnt;
			break;
		}
		mp[now]++;
		a.push_back(now);
		cnt++;
		ind[now]=cnt;
		ai = now;
	}
	ll sum = 0;
	if (circlep) {
		ll sumc = 0;
		ll suma = 0;
		rep(i,st) {
			sum += a[i];
		}
		for(ll i= st;i<=ed;i++){
			sumc += a[i];
		}
		ll nshow=(n-st)/(ed-st+1);
		ll amari=(n-st)%(ed-st+1);
		for(ll i= st;i< st+amari;i++){
			suma += a[i];
		}
		sum += suma;
		sum += sumc*nshow;
	} else {
		for(ll i= st;i<=ed;i++){
			sum += a[i];
		}
	}
	cout << sum << endl;
	return 0;
}
