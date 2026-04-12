#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	set<char> st;
	rep(i, 3) {
		char c;
		cin >> c;
		st.insert(c);
	}
	if(st.size()==1) cout << "No" << endl;
	else cout << "Yes" << endl;
	return 0;
}