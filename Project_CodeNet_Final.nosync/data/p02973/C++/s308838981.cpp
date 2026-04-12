#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i=0;i<n;i++)
#define REP(i, n) for(int i=1;i<=n;i++)
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	multiset<int> s;
	s.insert(a[0]);
	REP(i, n - 1) {
		int v = a[i];
		auto itr = s.lower_bound(v);
		if (itr != s.begin()) s.erase(--itr);
		s.insert(v);
	}
	int ans = int(s.size());
	cout << ans << endl;
	return 0;
}