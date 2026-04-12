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

const int mod = 1000000007;
int main() {
	ll n;
	cin >> n;
	vector<ll>a(n);
	rep(i, n)cin >> a[i];
	ll cnt(0);
	rep(i, n) {
		cnt += a[i];
	}
	ll ans(0);
	rep(i, n) {
		cnt -= a[i];
		ll k = cnt % mod;
		ans += a[i] * k;
		ans %= mod;
	}
	cout << ans;
	return 0;
}