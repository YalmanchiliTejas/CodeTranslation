#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using ldbl = long double;
using lpair = pair<llong, llong>;

#define ALL(x) x.begin(), x.end()

const llong inf = 1100100100100100ll;
const llong mod = 1e9+7;

int main() {
	llong N, cnt, before;
	vector<llong> A;

	cin >> N;
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}

	multiset<llong> ans;
	ans.insert(-1);
	for (int i = 0; i < N; ++i) {
		auto it = ans.lower_bound(A[i]);
		if (it == ans.begin()) {
			ans.insert(A[i]);
		} else {
			--it;
			ans.erase(it);
			ans.insert(A[i]);
		}
	}

	cout << ans.size() << endl;

	return 0;
}