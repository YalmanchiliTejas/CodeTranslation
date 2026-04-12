#include<bits/stdc++.h>
using namespace std;
int main () {
	string s;
	cin >> s;
	bool a = 0, b = 0;
	for (char &c : s) {
		if (c == 'A') a = 1;
		else b = 1;
	}
	cout << (a && b ? "Yes" : "No") << endl;
}
