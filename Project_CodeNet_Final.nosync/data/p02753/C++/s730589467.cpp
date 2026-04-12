#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	while(cin >> s) {
		int a[2]; a[0] = a[1] = 0;
		for(int i = 0; i < 3; i++) {
			a[s[i] - 'A']++;
		}
		string ans = "Yes";
		// cout << a[0] << " " << a[1] << endl;
		// cout << abs(a[0] - a[1]) << endl;
		if(abs(a[0] - a[1]) == 3) ans = "No";
		cout << ans << endl;
	}
	return 0;
}