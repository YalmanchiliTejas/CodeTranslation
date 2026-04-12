#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pf push_front
#define pii pair <int, int>
#define all(vv) (vv).begin(), (vv).end()
#define time cerr << '\n' << (double)clock()/CLOCKS_PER_SEC << '\n'; return 0

int n;
vector <int> x;
vector <int> y;

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; ++i) {
		int a; cin >> a;
		x.pb(a);
		y.pb(a);
	}
	sort(all(y));
	int lm = y[n/2-1];
	int rm = y[n/2];
	for(int i = 0; i < n; ++i) {
		if (x[i] <= lm) {
			cout << rm;
		}
		else {
			cout << lm;
		}
		cout << '\n';
	}
	time;
}