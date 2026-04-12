#include "bits/stdc++.h"
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std; 
typedef pair<int, int> P;

int main(){
	int N;
	cin >> N;
	vector<int>A(N);
	for (int n = 0;n<N;++n) {
		cin >> A[n];
	}
	multiset<int> st;
	for (int n = 0; n < N; ++n) {
		int now = A[n]; 
		auto itr = st.lower_bound(now);
		if (st.begin() != itr) {
			--itr;
			st.erase(itr);
		}
		st.insert(now);
	}
	cout << st.size()<<endl;
	return 0;
}