#include "bits/stdc++.h"
using namespace std;
string s;
int a, b;
int main() {
	cin >> s;
	for (int i=0; i<s.size(); i++) {
		if (s[i]=='A') a++;
		if (s[i]=='B') b++;
	}
	if (a>0 && b>0) cout << "Yes" << "\n";
	else cout << "No" << "\n";
	return 0;
}
