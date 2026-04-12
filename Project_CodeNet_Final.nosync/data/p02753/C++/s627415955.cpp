#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	string s;
	cin >> s;
	set<char> st;
	for (int i = 0; i < s.size(); ++i) { st.insert(s[i]); }

	cout << (st.size() > 1 ? "Yes" : "No") << endl;

	return 0;
}
