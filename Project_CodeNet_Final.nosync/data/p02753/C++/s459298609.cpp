#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int a = 0, b = 0;
	for(int i = 0; i <= 2; ++i) {
		if(s[i] == 'A') a = 1;
		if(s[i] == 'B') b = 1;
	}
	if(a == 1 && b == 1) cout << "Yes";
	else cout << "No";
	return 0;
}