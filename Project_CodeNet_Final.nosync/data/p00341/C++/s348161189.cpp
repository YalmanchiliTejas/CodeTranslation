#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
using namespace std;
int main() {
	int a[12];
	for (int i = 0; i < 12; i++) cin >> a[i];
	sort(a, a + 12);
	bool l = true;
	int b[12][2], c = 0;
	for (int i = 0; i < 12; i++) {
		if (i == 0) {
			b[c][0] = a[i];
			b[c][1] = 1;
			c++;
		}
		else {
			if (b[c - 1][0] == a[i]) {
				b[c - 1][1]++;
			}
			else {
				b[c][0] = a[i];
				b[c][1] = 1;
				c++;
			}
		}
	}
	if (c == 3) {
		for (int i = 0; i < c; i++) {
			if (b[i][1] != 4) {
				l = false;
			}
		}
	}
	else if (c == 2) {
		if ((b[0][1] == 8 && b[1][1] == 4) ||
			(b[0][1] == 4 && b[1][1] == 8)) {
			l = true;
		}
		else l = false;
	}
	else if (c == 1) {
		if (b[0][1] == 12) l = true;
		else l = false;
	}
	else {
		l = false;
	}
	if (l) cout << "yes" << endl;
	else cout << "no" << endl;
}