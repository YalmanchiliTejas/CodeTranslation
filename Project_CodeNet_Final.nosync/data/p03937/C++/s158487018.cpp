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
	int h, w,cnt=0;
	cin >> h >> w;
	char a[10][10];
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
			if (a[i][j] == '#')cnt++;
		}
	}
	if (cnt == h + w - 1) {
		cout << "Possible" << endl;
		return 0;
	}
	else cout << "Impossible" << endl;
	system("PAUSE");
	return 0;
}
