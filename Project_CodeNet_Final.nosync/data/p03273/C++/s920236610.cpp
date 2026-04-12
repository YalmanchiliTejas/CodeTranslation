#include <iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main() {
	int h;
	int w;
	char a[102][102];
	cin >> h;
	cin >> w;
	int b[102] = {};
	int c[102] = {};
	for (int i = 1; i < h + 1; i++) {
		for (int t = 1; t < w + 1; t++) {
			cin >> a[i][t];
			if (a[i][t] == '#') {
				b[i] = 1;
				c[t] = 1;
			}
		}

	}
	for (int i = 1; i < h + 1; i++) {
		for (int t = 1; t< w + 1; t++) {
			if (b[i] == 0)break;
			if (c[t] == 1)cout << a[i][t];
			if (t == w)cout << "\n";
		}

	}

}