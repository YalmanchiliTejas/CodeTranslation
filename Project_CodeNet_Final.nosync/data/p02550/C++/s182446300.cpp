#include<iostream>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int, int>;
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<set>

int main() {
	ll n, x, m;
	cin >> n >> x >> m;
	vector<ll>c;
	c.push_back(x);
	set<ll>s;
	ll cnt(0);
	ll ans(0);
	ans += c[0];
	bool ok = false;
	int key;
	rep(i, n-1) {
		int k = (c[i] * c[i]) % m;
		//cout << k;
		//cout << s.count(k)<<endl;
		if (s.count(k)) {
			key = k;
			ok = true;
			break;
		}
		else {
			s.insert(k);
			c.push_back(k);
			ans += k;
			cnt++;
		}
	}

	if (ok) {
		//ans -= key;
		//cout << ans << endl;;
		int i = 0;
		ll part(0);
		while (1) {
			if (c[i] == key)break;
			i++;
		}
		cnt++;
		ll amari = (n - i) % (cnt - i);
		ll kazu= (n - i) / (cnt - i);
		ll kaisuu = 0;
		//cout << kazu << " " << amari << " ";
		for (int j = i; j < c.size(); ++j) {
			part += c[j];
			
			kaisuu++;
			if (kaisuu == amari) {
				ans += part;
				//cout << part;
			}
		}
		ans += part * (kazu-1);
	}
	
	cout << ans;
	return 0;
}