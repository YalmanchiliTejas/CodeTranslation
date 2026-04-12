#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << #var << " = " << var;
#else
#define debug(var)
#endif

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

const int N = 2e5;

string s;
int n;
int a[N];

void done() {
	for (int i = 0; i < n; ++i) {
		cout << (a[i]?'W':'S');
	}
}

bool correct(int i) {
	if (!a[i]) {
		if (s[i] == 'o' && a[(i-1+n)%n] == a[(i+1)%n]) {
			return true;
		}
		if (s[i] == 'x' && a[(i-1+n)%n] != a[(i+1)%n]) {
			return true;
		}
	} else {
		if (s[i] == 'x' && a[(i-1+n)%n] == a[(i+1)%n]) {
			return true;
		}
		if (s[i] == 'o' && a[(i-1+n)%n] != a[(i+1)%n]) {
			return true;
		}
	}
	return false;
}

void solve() {
	cin >> n;
	cin >> s;
	for (a[0] = 0; a[0] < 2; ++a[0]) {
		for (a[1] = 0; a[1] < 2; ++a[1]) {
			for (int i = 2; i < n; ++i) {
				if (!a[i-1]) {
					if (s[i-1] == 'o') a[i] = a[i-2];
					else a[i] = !a[i-2];
				} else {
					if (s[i-1] == 'x') a[i] = a[i-2];
					else a[i] = !a[i-2];
				}
			}
			bool good = true;
			for (int i = 0; i < n; ++i) {
				if (!correct(i)) {
					good = false;
					break;
				}
			}
			if (good) {
				done();
				return;
			}
				
		}
	}
	cout << -1;
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
