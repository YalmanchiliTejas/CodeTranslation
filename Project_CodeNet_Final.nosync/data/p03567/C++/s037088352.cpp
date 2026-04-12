#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string s;
	cin >> s;
	for (int i = 1; i < s.length(); i++) {
		string t = s.substr(i - 1, 2);
		if (t == "AC") {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
}