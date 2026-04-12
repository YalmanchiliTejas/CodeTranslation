#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef _DEBUG
	freopen("in" , "r", stdin );
	//freopen("out", "w", stdout);
#endif
	string s; cin >> s;
	for (int i = 0; i < (int) s.size() - 1; i++) {
		if (s[i] != s[i + 1]) {
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
}