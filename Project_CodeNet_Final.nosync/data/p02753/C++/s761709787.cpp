#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	char ch[4];
	cin >> ch;
	int a, b;
	for (int i = 0; i < 4; i++) {
		if (ch[i] == 'A') a++;
		if (ch[i] == 'B') b++;
	}
	if (a && b) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}