#include <bits/stdc++.h>
using namespace std;

void compress(vector<int>& v) {
	auto vs = v;
	sort(vs.begin(), vs.end());
	vs.erase(unique(vs.begin(), vs.end()), vs.end());
	for (auto& val : v) {
		val = lower_bound(vs.begin(), vs.end(), val) - vs.begin();
	}
}

int main()
{
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	compress(A);
	map<int, int> st;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		auto it = st.upper_bound(-A[i]);
		if (it == st.end()) {
			++cnt;
			st[-A[i]]++;
		}
		else {
			--it->second;
			if (it->second == 0) st.erase(it);
			st[-A[i]]++;
		}
	}
	cout << cnt << endl;
	return 0;
}
