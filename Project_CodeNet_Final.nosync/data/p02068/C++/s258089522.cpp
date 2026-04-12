#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int a[n]; for(int i = 0; i < n; ++i) cin >> a[i];
	set<int> st;
	for(int i = 0; i < n; ++i) {
		int tmp = a[i];
		for(int j = 2; j * j <= tmp; ++j) {
			while(tmp % j == 0) {
				st.insert(j);
				st.insert(tmp / j);
				tmp /= j;
			}
		}
		st.insert(tmp);
	}
	int64_t ans = 0;
	for(int k : st) {
		if(k < 2) continue;
		int64_t tmp = 0;
		for(int i = 0; i < n; ++i) {
			if(a[i] % k == 0) tmp += a[i];
		}
		ans = max(ans, tmp);
	}
	cout << ans << '\n';
	return 0;
}
