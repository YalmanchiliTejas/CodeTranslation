#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int a[maxn];
multiset<int> st;
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (st.size() == 0) {
			st.insert(a[i]);
		} else {
			multiset<int> ::iterator iter = st.lower_bound(a[i]);
			if (iter == st.begin()) {
				st.insert(a[i]);
			} else {
				iter--;
				st.erase(iter); st.insert(a[i]);
			}
		}
	}
	cout << st.size() << endl;
	return 0;
}
