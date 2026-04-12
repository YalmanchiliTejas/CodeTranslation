#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <time.h>
using namespace std;
typedef long long ll;
bool x[110], y[110];
int main() {
	int h, w;
	cin >> h >> w;
	char a[110][110];
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)cin >> a[i][j];
	}
	for (int i = 0; i < h; i++) {
		bool f = false;
		for (int j = 0; j < w; j++) {
			if (a[i][j] == '#') {
				f = true;
			}
		}
		if (!f)x[i] = true;
	}
	for (int i = 0; i < w; i++) {
		bool f = false;
		for (int j = 0; j < h; j++) {
			if (a[j][i] == '#')f = true;
		}
		if (!f)y[i] = true;
	}
	for (int i = 0; i < h; i++) {
		if (x[i])continue;
		for (int j = 0; j < w; j++) {
			if (y[j])continue;
			cout << a[i][j];
		}
		cout << endl;
	}
	system("PAUSE");
	return 0;
}
