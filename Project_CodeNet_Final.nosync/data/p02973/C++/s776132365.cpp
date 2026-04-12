#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e10;

int main() {
	int N;
	cin >> N;
	vector<ll> A(N);
	for(auto &a : A) cin >> a;
	multiset<ll> st;
	st.insert(A[0]);
	for(int i=1;i<N;i++) {
		auto itr = st.lower_bound(A[i]);
		// 存在しなかった
		if(itr == st.begin()) {
			// A[i]を挿入
			st.insert(A[i]);
		} else {
			itr--;
			st.erase(itr);
			st.insert(A[i]);
		}
	}
	cout << st.size() << endl;
}