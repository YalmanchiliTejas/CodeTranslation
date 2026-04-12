#include<bits/stdc++.h>
using namespace std;
typedef long long ll; typedef double db;
typedef pair<int, int> pii; typedef pair<ll, ll> pll;
typedef vector<int> vi; typedef vector<ll> vl;
typedef vector<pii> vpii; typedef vector<pll> vpll;
#define FOR(n) for(int i=0;i<n;++i)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll gcd(ll a, ll b) { return a % b ? gcd(b, a % b) : b; }
const ll inf = 0x3f3f3f3f;
map<ll, int>ha;
ll cnt=-1, ans;
vector<ll>sum(1, 0);
signed main() {
	ll n, x, m;
	cin >> n >> x >> m;
	ha[x] = 1;
	sum.push_back(x);
	ll i;
	for (i = 2; i <= n; ++i) {
		x *= x;
		x %= m;
		sum.push_back(sum[i - 1] + x);
		if (ha[x]) {
			cnt = i - ha[x];
			break;
		}
		ha[x] = i;
	}
	if (cnt < 0) {
		cout << sum[i - 1] << endl;
		return 0;
	}
	ans = sum[i];
	ll tempsum = sum[i] - sum[ha[x]];
	ll time = (n - i) / cnt;
	ans += time * tempsum;
	i += cnt * time;
	for (i++; i <= n; ++i) {
		x *= x;
		x %= m;
		ans += x;
	}
	cout << ans << endl;
}