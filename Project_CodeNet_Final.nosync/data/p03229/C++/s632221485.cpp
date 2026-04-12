#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<double, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	sort(all(a));
	auto dsum = [&](auto it1, auto it2) {
		vector<int> b(n);
		for (int i = 1; i < n - 1; ++i) {
			b[i] = (i % 2 == 0) ? *it1++ : *it2++;
		}
		b[0] = *it1;
		b[n - 1] = *it2;
		ll res = 0;
		rep(i, n - 1) res += abs(b[i + 1] - b[i]);
		return res;
	};
	ll ans = max(dsum(a.begin(), a.rbegin()), dsum(a.rbegin(), a.begin()));
	cout << ans << endl;
 	return 0;
}
