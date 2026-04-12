#include <iostream>
#include<vector>
#include<algorithm>
#include <queue>
#include <string>
#include <set>
#include <bitset>

using namespace std;
#define ff(i,n,m) for(int i=n;i<m;i++)
#define i64 int64_t
#define tos(x) to_string(x)


char anti(char sw) {
	if (sw == 'S') {
		return 'W';
	}
	else {
		return 'S';
	}
}


int main() {
	int n;
	cin >> n;
	string a;
	cin >> a;
	vector<char> ans(n);
	//case 1 SS
	ans.at(0) = 'S';
	ans.at(1) = 'S';
	ff(i, 1, n - 1) {
		if (ans.at(i) == 'S') {
			if (a[i] == 'o') {
				ans.at(i + 1) = ans.at(i - 1);
			}
			else {
				ans.at(i + 1) = anti(ans.at(i - 1));
			}
		}
		else {
			if (a[i] == 'o') {
				ans.at(i + 1) = anti(ans.at(i - 1));
			}
			else {
				ans.at(i + 1) = ans.at(i - 1);
			}
		}
	}
	int okp = 0;
	if (a[n - 1] == 'o') {
		if (ans.at(n - 1) == 'S' && ans.at(n - 2) == ans.at(0)) {
			okp++;
		}
		else if (ans.at(n - 1) == 'W' && ans.at(n - 2) != ans.at(0)) {
			okp++;
		}
	}
	else {
		if (ans.at(n - 1) == 'S' && ans.at(n - 2) != ans.at(0)) {
			okp++;
		}
		else if (ans.at(n - 1) == 'W' && ans.at(n - 2) == ans.at(0)) {
			okp++;
		}
	}
	if (a[0] == 'o') {
		if (ans.at(0) == 'S' && ans.at(n - 1) == ans.at(1)) {
			okp++;
		}
		else if (ans.at(0) == 'W' && ans.at(n - 1) != ans.at(1)) {
			okp++;
		}
	}
	else {
		if (ans.at(0) == 'S' && ans.at(n - 1) != ans.at(1)) {
			okp++;
		}
		else if (ans.at(0) == 'W' && ans.at(n - 1) == ans.at(1)) {
			okp++;
		}
	}
	if (okp == 2) {
		ff(i, 0, n) {
			cout << ans.at(i);
		}
		cout << endl;
		return 0;
	}
	
	//case 2 SW
	ans.at(0) = 'S';
	ans.at(1) = 'W';
	ff(i, 1, n - 1) {
		if (ans.at(i) == 'S') {
			if (a[i] == 'o') {
				ans.at(i + 1) = ans.at(i - 1);
			}
			else {
				ans.at(i + 1) = anti(ans.at(i - 1));
			}
		}
		else {
			if (a[i] == 'o') {
				ans.at(i + 1) = anti(ans.at(i - 1));
			}
			else {
				ans.at(i + 1) = ans.at(i - 1);
			}
		}
	}
	okp = 0;
	if (a[n - 1] == 'o') {
		if (ans.at(n - 1) == 'S' && ans.at(n - 2) == ans.at(0)) {
			okp++;
		}
		else if (ans.at(n - 1) == 'W' && ans.at(n - 2) != ans.at(0)) {
			okp++;
		}
	}
	else {
		if (ans.at(n - 1) == 'S' && ans.at(n - 2) != ans.at(0)) {
			okp++;
		}
		else if (ans.at(n - 1) == 'W' && ans.at(n - 2) == ans.at(0)) {
			okp++;
		}
	}
	if (a[0] == 'o') {
		if (ans.at(0) == 'S' && ans.at(n - 1) == ans.at(1)) {
			okp++;
		}
		else if (ans.at(0) == 'W' && ans.at(n - 1) != ans.at(1)) {
			okp++;
		}
	}
	else {
		if (ans.at(0) == 'S' && ans.at(n - 1) != ans.at(1)) {
			okp++;
		}
		else if (ans.at(0) == 'W' && ans.at(n - 1) == ans.at(1)) {
			okp++;
		}
	}
	if (okp == 2) {
		ff(i, 0, n) {
			cout << ans.at(i);
		}
		cout << endl;
		return 0;
	}
	//case 3 WS
	ans.at(0) = 'W';
	ans.at(1) = 'S';
	ff(i, 1, n - 1) {
		if (ans.at(i) == 'S') {
			if (a[i] == 'o') {
				ans.at(i + 1) = ans.at(i - 1);
			}
			else {
				ans.at(i + 1) = anti(ans.at(i - 1));
			}
		}
		else {
			if (a[i] == 'o') {
				ans.at(i + 1) = anti(ans.at(i - 1));
			}
			else {
				ans.at(i + 1) = ans.at(i - 1);
			}
		}
	}
	okp = 0;
	if (a[n - 1] == 'o') {
		if (ans.at(n - 1) == 'S' && ans.at(n - 2) == ans.at(0)) {
			okp++;
		}
		else if (ans.at(n - 1) == 'W' && ans.at(n - 2) != ans.at(0)) {
			okp++;
		}
	}
	else {
		if (ans.at(n - 1) == 'S' && ans.at(n - 2) != ans.at(0)) {
			okp++;
		}
		else if (ans.at(n - 1) == 'W' && ans.at(n - 2) == ans.at(0)) {
			okp++;
		}
	}
	if (a[0] == 'o') {
		if (ans.at(0) == 'S' && ans.at(n - 1) == ans.at(1)) {
			okp++;
		}
		else if (ans.at(0) == 'W' && ans.at(n - 1) != ans.at(1)) {
			okp++;
		}
	}
	else {
		if (ans.at(0) == 'S' && ans.at(n - 1) != ans.at(1)) {
			okp++;
		}
		else if (ans.at(0) == 'W' && ans.at(n - 1) == ans.at(1)) {
			okp++;
		}
	}
	if (okp == 2) {
		ff(i, 0, n) {
			cout << ans.at(i);
		}
		cout << endl;
		return 0;
	}
	//case 4 WW
	ans.at(0) = 'W';
	ans.at(1) = 'W';
	ff(i, 1, n - 1) {
		if (ans.at(i) == 'S') {
			if (a[i] == 'o') {
				ans.at(i + 1) = ans.at(i - 1);
			}
			else {
				ans.at(i + 1) = anti(ans.at(i - 1));
			}
		}
		else {
			if (a[i] == 'o') {
				ans.at(i + 1) = anti(ans.at(i - 1));
			}
			else {
				ans.at(i + 1) = ans.at(i - 1);
			}
		}
	}
	okp = 0;
	if (a[n - 1] == 'o') {
		if (ans.at(n - 1) == 'S' && ans.at(n - 2) == ans.at(0)) {
			okp++;
		}
		else if (ans.at(n - 1) == 'W' && ans.at(n - 2) != ans.at(0)) {
			okp++;
		}
	}
	else {
		if (ans.at(n - 1) == 'S' && ans.at(n - 2) != ans.at(0)) {
			okp++;
		}
		else if (ans.at(n - 1) == 'W' && ans.at(n - 2) == ans.at(0)) {
			okp++;
		}
	}
	if (a[0] == 'o') {
		if (ans.at(0) == 'S' && ans.at(n - 1) == ans.at(1)) {
			okp++;
		}
		else if (ans.at(0) == 'W' && ans.at(n - 1) != ans.at(1)) {
			okp++;
		}
	}
	else {
		if (ans.at(0) == 'S' && ans.at(n - 1) != ans.at(1)) {
			okp++;
		}
		else if (ans.at(0) == 'W' && ans.at(n - 1) == ans.at(1)) {
			okp++;
		}
	}
	if (okp == 2) {
		ff(i, 0, n) {
			cout << ans.at(i);
		}
		cout << endl;
		return 0;
	}
	//conclusion
	cout << -1 << endl;
	return 0;
}