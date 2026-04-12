#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;

bool b[200][200];
int main() {
	int n; cin >> n;
	int cnt = 0;
	rep(i, n)for (int j = i + 1; j < n; j++) {
		if (cnt == n - 1)break;
		string s(n, '0'); s[i] = '1'; s[j] = '1';
		cout << "? " << s << endl;
		int res; cin >> res;
		if (res == 1) {
			b[i][j] = 1; cnt++;
		}
	}
	cout << "!";
	rep(i, n)for (int j = i + 1; j < n; j++) {
		if (b[i][j]) {
			cout << " ";
			cout << "(" << i  << "," << j << ")";
		}
	}
	cout << endl;
}