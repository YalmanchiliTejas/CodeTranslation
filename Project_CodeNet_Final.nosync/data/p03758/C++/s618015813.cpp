#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;

int b[200][200];
int n;
int ask(int i, int j) {
	string s = string(n, '0');
	s[i] = '1'; s[j] = '1';
	cout << "? " << s << endl;
	int res; cin >> res;
	return res;
}
int main() {
	cin >> n;
	int cnt = 0;
	memset(b, -1, sizeof(b));
	rep(i, n)for (int j = i + 1; j < n; j += 2) {
		if (cnt == n - 1)break;
		if (b[i][j] != -1) {
			j--; continue;
		}
		string s(n, '0'); s[i] = '1'; s[j] = '1';
		if (j + 1 < n)s[j + 1] = '1';
		cout << "? " << s << endl;
		int res; cin >> res;
		if (res == 0) {
			b[i][j] = 0; 
			if (j + 1 < n) {
				b[i][j + 1] = 0;
				b[j][j + 1] = 0;
			}
			continue;
		}
		if (j + 1 == n) {
			b[i][j] = 1; cnt++; continue;
		}
		int a = 0;
		if (ask(i, j)) {
			a++; b[i][j] = 1; cnt++;
		}
		else b[i][j] = 0;
		if (ask(i, j + 1)) {
			a++; b[i][j + 1] = 1; cnt++;
		}
		else b[i][j + 1] = 0;
		if (a == 2) {
			b[j][j + 1] = 0;
		}
		if (res == 2 && a != 2)b[j][j + 1] = 1;
	}
	cout << "!";
	rep(i, n)for (int j = i + 1; j < n; j++) {
		if (b[i][j]) {
			if (b[i][j] == -1)abort();
			cout << " ";
			cout << "(" << i << "," << j << ")";
		}
	}
	cout << endl;
}