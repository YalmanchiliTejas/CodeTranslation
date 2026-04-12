#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;

	int a = 0; int b = 0;
	for (int i = 0; i < 3; i++) {
		if (s[i] == 'A') a += 1;
		else b += 1;
	}
	if (a * b) cout << "Yes" << endl;
	else cout << "No" << endl;
}
