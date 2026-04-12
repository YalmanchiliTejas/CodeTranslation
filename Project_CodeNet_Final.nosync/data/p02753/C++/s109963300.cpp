#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s; cin >> s;
	if (s[0] != s[1] || s[1] != s[2]) {
		cout << "Yes";
	} else {
		cout << "No";
	}
	return 0;
} 
 
