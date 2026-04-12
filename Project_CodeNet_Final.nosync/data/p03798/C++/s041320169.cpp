#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


int n;
string s;
int a[100010];


void solve() {
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			cout << 'S';
		} else {
			cout << 'W';
		}
	}
	cout << endl;
}

bool judge(int a, char c, int x, int y) {
	if (a == 0 && c == 'o' && x == y) {
		return true;
	} else if (a == 0 && c == 'x' && x != y) {
		return true;
	} else if (a == 1 && c == 'o' && x != y) {
		return true;
	} else if (a == 1 && c == 'x' && x == y) {
		return true;
	} else {
		return false;
	}
}


int main() {
	
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++) {
		a[i] = 0;
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			a[0] = i;
			a[1] = j;
			for (int k = 2; k < n; k++) {
				if (a[k - 1] == 0 && s[k - 1] =='o') {
					a[k] = a[k - 2];
				}else if (a[k - 1] == 0 && s[k - 1] =='x') {
					a[k] = a[k - 2] ^ 1;
				}else if (a[k - 1] == 1 && s[k - 1] == 'o') {
					a[k] = a[k - 2] ^ 1;
				}else if (a[k - 1] == 1 && s[k - 1] == 'x'){
					a[k] = a[k - 2];
				}
			}

			if (judge(a[0], s[0], a[1], a[n - 1]) && judge(a[n- 1], s[n - 1], a[n - 2], a[0])) {
				solve();
				return 0;
			}
		}
	}
	
	cout << -1 << endl;
	
	
	return 0;
}