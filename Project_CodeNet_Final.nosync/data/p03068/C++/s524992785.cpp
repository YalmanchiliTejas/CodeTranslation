#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int k;
	cin >> k;
	char c = s.at(k-1);
	for (int i = 0; i < n; i++) {
		if (s.at(i) == c)cout << c;
		else cout << "*";
	}
}