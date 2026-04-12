#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	int a=0,b=0;
	for (int i=0; i<3; i++) {
		if (s[i]=='A') a++;
		else b++;
	}
	if (a==1 && b==2) cout << "Yes";
	else if (b==1 && a==2) cout << "Yes";
	else cout << "No";
	return 0;
}