#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	int n, k;
	cin >> n >> s >> k;
	char A = s.at(k-1);
	for (int i = 0; i < n; i++) {
		if (s.at(i) != A) s.replace(i, 1, 1, '*');
	}
	cout << s << endl;
}