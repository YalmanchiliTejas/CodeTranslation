#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s; cin >> s;
	unordered_set<char> c;
	for (auto i : s) {
		c.insert(i);
	}
	if (c.size() == 1) {cout << "No";}
	else {cout << "Yes";}
}

