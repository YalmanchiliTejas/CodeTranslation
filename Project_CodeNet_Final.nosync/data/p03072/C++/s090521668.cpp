#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
	int n;
	cin >> n;
	int maxH = 0;
	int cnt = 0;
	rep(i, n) {
		int h;
		cin >> h;
		if (h >= maxH) {
			cnt++;
			maxH = h;
		}
	}
	if (cnt == 0) cout << 1 << endl;
	else cout << cnt << endl;
	return 0;
}
