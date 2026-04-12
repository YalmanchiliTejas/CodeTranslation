#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; ++i) { cin >> a[i]; }

	multiset<int> st;
	st.insert(-a[0]);
	for (int i = 1; i < N; ++i) {
		auto it = st.upper_bound(-a[i]);
		if (it != st.end()) {
			st.erase(it);
		}
		st.insert(-a[i]);
	}
	cout << st.size() << endl;

	return 0;
}
