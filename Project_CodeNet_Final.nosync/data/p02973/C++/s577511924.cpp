#include "bits/stdc++.h"

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	multiset< int> st;

	int result = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		auto it = st.lower_bound(x);
		if (it == st.begin()) {
			result ++;
		} else {
			it --;
			st.erase(it);
		}
		st.insert(x);
	}

	cout << result << endl;
}