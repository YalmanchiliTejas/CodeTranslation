#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<int> c;
	rep(i, n) {
		bool ok = false;
		int p = lower_bound(all(c), a[i]) - c.begin() - 1;
		if(p >= 0) {
			ok = true;
			c[p] = a[i];
		} 
		if(!ok) {
			auto it = c.begin();
			it = c.insert(it, a[i]);
		}
		// rep(i, c.size()) cout << c[i] << " ";
		// cout << endl;
	}
	cout << c.size() << endl;
	return 0;
}
