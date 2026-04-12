#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	string s;

	cin >> s;
	if (s[0] != s[1] or s[1] != s[2])
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}