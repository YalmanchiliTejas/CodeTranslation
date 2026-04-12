#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
	
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	
	multiset<int> st;
	rep(i,n){
		if(!st.empty()){
			auto itr = st.lower_bound(a[i]);
			if(itr != st.begin()) st.erase(--itr);
		}
		st.insert(a[i]);
	}
	
	cout << st.size() << endl;
	return 0;
}
