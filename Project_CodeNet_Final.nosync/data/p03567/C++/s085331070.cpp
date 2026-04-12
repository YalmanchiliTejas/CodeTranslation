#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	bool ans = false;
	cin >> s;
	for (int i = 0;i < s.size()-1;++i) {
		if (s[i] == 'A' && s[i+1] == 'C') ans = true;
	}
	if (ans) cout << "Yes" << "\n";
	else cout << "No" << "\n";
	return 0;
}