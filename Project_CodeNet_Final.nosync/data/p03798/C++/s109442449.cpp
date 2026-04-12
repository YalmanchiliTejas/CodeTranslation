#include <bits/stdc++.h>
using namespace std;
#define v1 (2 * v + 1)
#define v2 (2 * v + 2)
#define size(a) ((ll)a.size())
typedef long long ll;

const int N = 1e5 + 100;
int a[N], n, b[N];
string s;

bool good(int x, int y) {
	a[0] = x;
	a[1] = y;
	for (int i = 1; i < n; i++) {
		if (a[i]) {
			if (b[i]) a[i + 1] = a[i - 1];
			else a[i + 1] = !a[i - 1];
		} else {
			if (b[i]) a[i + 1] = !a[i - 1];
			else a[i + 1] = a[i - 1];
		}
	}
	bool fl = true;
	for (int i = 0; i <= n; i++) {
		int x = i % n;
		int next = (i + 1) % n;
		int prev = (i - 1 + n) % n;
		if (a[x]) {
			if (b[x]) {
				if (a[prev] != a[next]) fl = false;
			} else {
				if (a[prev] == a[next]) fl = false;
			}
		} else {
			if (b[x]) {
				if (a[prev] == a[next]) fl = false;
			} else {
				if (a[prev] != a[next]) fl = false;
			}
		}
	}
	return fl;
}

int main() {
#ifdef RUZAL
    freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
#else
    //freopen("sum0.in", "r", stdin); freopen("sum0.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); //cin.tie(NULL);  + 1cout.tie(NULL);

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'o') b[i] = 1;
		else b[i] = 0;
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (good(i, j)) {
				for (int i = 0; i < n; i++) {
					if (a[i]) {
						cout << "S";
					} else {
						cout << "W";
					}
				}
				return 0;
			}
		}
	}

	cout << -1 << endl;

    return 0;
}