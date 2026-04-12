#include<bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(false);cin.tie(0);
#define __ cout<<fixed;cout<<setprecision(10);
#define int long long


int32_t main() {
	_ __

#ifdef LOCAL_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, x, m;
	cin >> n >> x >> m;
	int i = 0;
	int sum = 0;
	int init = x;
	int over[m] = {0};
	vector<int> p;
	x %= m;
	while (over[x] == 0 && i < n) {
		p.push_back(x);
		over[x] = 1;
		sum += x;
		x *= x;
		x %= m;
		if (x == 0) {
			cout << sum << "\n";
			return 0;
		}
		i++;
	}
	if (p.size() > 0) {
		reverse(p.begin(), p.end());
		while (p.size() > 0 && p.back() != x) {
			p.pop_back();
		}
		reverse(p.begin(), p.end());
	}
	int temp = 0;
	for (int i = 0; i < (int)p.size(); i++) {
		temp += p[i];
	}
	if (p.size() > 0)
		init = p[0];
	if (i < n) {
		int left = n - i;
		int done = p.size();
		int xx = left / done;
		int rem = left % done;
		sum += xx * temp;
		while (rem--) {
			sum += init;
			init *= init;
			init %= m;
		}
	}
	cout << sum << "\n";




#ifdef LOCAL_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
#endif

	return 0;
}