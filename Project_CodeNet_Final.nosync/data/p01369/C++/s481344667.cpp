#include <bits/stdc++.h>
using namespace std;

bool incCheck(char c, vector<char> v) {
	for (auto e : v) {
		if (c == e) {
			return true;
		}
	}
	return false;
}

signed main() {
	vector<char> left = {'q', 'a', 'z', 'w', 's', 'x', 'e', 'd', 'c', 'r', 'f', 'v', 't', 'g', 'b'};
	vector<char> right = {'y', 'h', 'n', 'u', 'j', 'm', 'i', 'k', 'o', 'l', 'p'};

	string s;
	


	while (cin >> s and s != "#") {
		bool isLeft = false;
		int cnt = 0;
		isLeft = incCheck(s[0], left);

		for (int i = 1; i < s.size(); ++i) {
			if (isLeft) {
				if (!incCheck(s[i], left)) {
					cnt++;
					isLeft = false;
				}
			}
			else {
				if (incCheck(s[i], left)) {
					cnt++;
					isLeft = true;
				}
			}
		}
		cout << cnt << endl;
	}
}	

