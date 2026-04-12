#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e10;

int main() {
	int N;
	cin >> N;
	vector<ll> A(N);
	for(auto &a : A) cin >> a;
	vector<ll> vec;
	vec.push_back(-A[0]);
	for(int i=1;i<N;i++) {
		auto itr = upper_bound(vec.begin(), vec.end(), -A[i]);
		// 存在しなかった
		if(itr == vec.end()) {
			// A[i]を挿入
			vec.push_back(-A[i]);
		} else {
			*itr = -A[i];
		}
	}
	cout << vec.size() << endl;
}