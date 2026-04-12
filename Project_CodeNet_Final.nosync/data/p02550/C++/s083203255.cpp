#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n, x, m;
	cin >> n >> x >> m;

	vector<ll> v(m+10, 0);
	v[1] = x;
	map<ll, int> mp;
	mp[v[1]] = 1;
	vector<ll> s(m+10, 0);
	s[1] = v[1];
	int l = -1, r = -1;
	for(int i = 2; i <= min(m + 9, n); i++){
		v[i] = v[i-1] * v[i-1];
		v[i] %= m;
		s[i] = s[i-1] + v[i];

		if(mp.count(v[i]) == 1){
			l = mp[v[i]];
			r = i;
			break;
		}

		mp[v[i]] = i;
	}

	if(l == -1){
		cout << s[n] << endl;
		exit(0);
	}else{
		ll ans = s[l-1];
		ll qu = (n - l + 1) / (r - l);

		ll re = (n - l + 1) % (r - l);

		ans += (s[r-1]- s[l-1]) * qu;
		rep(i, re) {
			ans += v[l + i];
		}

		cout << ans << endl;
	}

}
