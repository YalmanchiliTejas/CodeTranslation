#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, mi = 55;
	int c[125][125];
	int m[125];
	string s, w, ans = "";

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 97; j < 124; j++) {
			c[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			w = s.substr(j, 1);
			char z = *w.c_str();
			c[i][z + 0]++;
		}
	}
	for (int i = 97; i < 124; i++) {
		for (int j = 0; j < n; j++) {
			mi = min(c[j][i], mi);
		}
		m[i] = mi;
		mi = 55;
	}
	for (int i = 97; i < 124; i++) {
		for (int j = 0; j < m[i]; j++) {
			cout << char(i);
		}
	}
	cout << endl;

	return 0;
}
