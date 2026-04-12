#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

int main() {
	int n, k;
	string s;
	cin >> n >> s >> k;
	k--;

	for (int i = 0; i < n; i++) {
		if (s[i] != s[k]) {
			s[i] = '*';
		}
	}

	cout << s << endl;
	return 0;
}
