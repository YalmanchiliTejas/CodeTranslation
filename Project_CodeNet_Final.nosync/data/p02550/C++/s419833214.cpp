#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dup(x,y) (((x)+(y)-1)/(y))
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
	ll n, x, m;
	cin >> n >> x >> m;
	map<ll, int> mp;
	vector<ll> v;
	ll a = x;
	int k = -1;
	for (int i = 0; i < m; i++) {
		if (mp[a]) {
			k = i;
			break;
		}
		mp[a] = i;
		v.push_back(a);
		a = (a * a) % m;
	}
	int s = mp[a];
	if (n <= s) {
		ll ans = 0;
		rep(i,n) {
			ans += v[i];
		}
		cout << ans << endl;
		return 0;
	}
	int t = k - mp[a];

	ll w = 0;
	ll y = 0;
	rep(i,(int)v.size()) {
		if (i < s) w += v[i];
		else y += v[i];
	}
	if (n <= s) {
		ll ans = 0;
		rep(i,n) {
			ans += v[i];
		}
		cout << ans << endl;
	} else {
		ll z = 0;
		for (int i = 0; i < (n - s) % t; i++) {
			z += v[i+s];
		}
		cout << w + (n - s) / t * y + z << endl;
	}
}