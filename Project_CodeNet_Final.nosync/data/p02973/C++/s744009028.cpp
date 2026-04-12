#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	ll N;
	cin >> N;
	vector <ll> A(N, 0);
	for (ll ii = 0; ii < N; ++ii){
		ll tmp;
		cin >> tmp;
		A[ii] = -tmp;
	}

	vector <ll> ans;
	for (ll ii = 0; ii < N; ++ii){
		auto itr = upper_bound(ans.begin(), ans.end(), A[ii]);
		if (itr == ans.end()) {
			ans.push_back(A[ii]);
		} else {
			*itr = A[ii];
		}
	}

	cout << ans.size() << endl;
	

	return 0;
}
