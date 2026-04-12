#include <bits/stdc++.h>
using namespace std;

#define int long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

signed main(){
	int n;
	cin >> n;

	int a[100010];
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}

	multiset<int> st;

	for(int i = 0;i < n;i++){
		auto idx = st.lower_bound(a[i]);
		if(idx != st.begin()){
			idx--;
			st.erase(idx);
		}
		st.insert(a[i]);
	}

	cout << st.size() << endl;

	return 0;
}
