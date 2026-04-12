#include <bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define ff first
#define ss second
#define P 1000000007
#define in(x, a, b) (a <= x && x < b)

using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
const ll inf = 1000000001, INF = (ll)1e18 + 1;

void solve() {
	ll n, x, m;
	cin >> n >> x >> m;
	
	if(x == 0) {
		cout << 0 << endl;
		return;
	}
	
	int ok = 1;
	ll sum = x;
	vector<ll> a(1, x);
	vi seen(m + 1, 0);
	seen[a.back()] = 1;
	for(int i = 2; i <= n; i++) {
		ll res = (a.back() * a.back()) % m;
		
		if(res == 0) {
			cout << sum << endl;
			return;
		}
		
		if(!seen[res]) {
			a.pub(res);
			sum += a.back();
			seen[res] = i;
		} else {
			ok = 0;
			break;
		}
	}
	
	ll ans = sum;
//	if(!ok) {
		n -= a.size();
		ll rep = n / (a.size() - seen[(a.back() * a.back()) % m] + 1);
		sum = 0;
		for(int i = seen[(a.back() * a.back()) % m] - 1; i < a.size(); i++) sum += a[i];
		ans += rep * sum;
		n -= rep * (a.size() - seen[(a.back() * a.back()) % m] + 1);
		for(int i = seen[(a.back() * a.back()) % m] - 1; i < seen[(a.back() * a.back()) % m] + n - 1; i++) ans += a[i];
//	}
	
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	solve();
    return 0;
}