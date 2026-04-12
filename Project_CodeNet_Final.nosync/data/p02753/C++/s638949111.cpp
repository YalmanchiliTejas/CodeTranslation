#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int main() {
	string s;
	cin >> s;
	int a, b;
	a = b = 0;
	for (char c : s) {
		if (c == 'A') a++;
		else b++;
	}
	cout << (a*b > 0 ? "Yes" : "No") << endl;
	return 0;
}