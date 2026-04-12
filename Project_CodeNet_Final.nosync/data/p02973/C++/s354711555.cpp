#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 3;
int n, a[N];
int main() {
#ifndef ONLINE_JUDGE
//	freopen("input.in", "r", stdin);
#endif
	scanf("%d", &n);
	multiset<int> st;
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	st.insert(a[n - 1]);
	for (int i = n - 2; i >= 0; --i) {
		auto it = st.lower_bound(a[i] + 1);
		if (it != st.end()) {
			st.erase(it);
			st.insert(a[i]);
		}else {
			st.insert(a[i]);
		}
	}
	printf("%d\n", st.size());
	return 0;
}