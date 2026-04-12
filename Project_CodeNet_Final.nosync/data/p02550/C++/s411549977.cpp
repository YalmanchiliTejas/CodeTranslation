#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;

#define STRING(str) #str
#define ll long long

template <typename T >
void print_vec_1d(vector<T> x, string name) {
	cout << name << endl;
	cout << "[ ";
	for (int i=0;i<x.size();i++) {
		cout << x[i];
		if (i != x.size()-1) cout << ", ";
		else cout << " ]" << endl;
	}
}


int main() {
	ll N, X, M;
	cin >> N >> X >> M;

	set<ll> st;
	ll tmp = X;
	ll cycle = 0LL;
	int cycle_len = 0;
	vector<ll> cycle_val;
	bool last_zero = false;
	int double_ind = -1;
	// while (!st.count(tmp)) {
	while (true) {

		if (st.count(tmp)) {
			for (int i=0;i<cycle_val.size();i++) {
				double_ind = i;
				if (tmp == cycle_val[i]) break;
			}
			break;
		}

		st.insert(tmp);
		if (tmp == 0) last_zero = true;
		cycle_val.push_back(tmp);
		cycle_len++;
		cycle += tmp;
		tmp = tmp*tmp%M;
		if (cycle_len == N) break;
	}

	if (last_zero) {
		cout << cycle << endl;
	} else {
		ll ans = 0LL;
		// ans += cycle*(N/cycle_len);
		// for (int i=0;i<(N%cycle_len);i++) {
		// 	ans += cycle_val[i];
		// }

		ll true_cycle = cycle;
		ll true_cycle_len = cycle_len-double_ind;
		for (int i=0;i<double_ind;i++) {
			ans += cycle_val[i];
			true_cycle -= cycle_val[i];
		}
		ans += true_cycle*((N-double_ind)/true_cycle_len);
		for (int i=0;i<(N-double_ind)%true_cycle_len;i++) {
			ans += cycle_val[i+double_ind];
		}

		cout << ans << endl;
	}
}