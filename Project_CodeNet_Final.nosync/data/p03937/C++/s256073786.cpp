#include <bits/stdc++.h>
using namespace std;

int h, w;
char a[8][8];
bool search(int i, int j) {
	if (i >= h || j >= w || a[i][j] == '.') {
		return false;
	}
	if (i == h - 1 && j == w - 1) {
		return true;
	}
	if (search(i + 1, j) || search(i, j + 1)) {
		return true;
	}
}

int main(){
	cin >> h >> w;
	int count = 0;
	for (int i = 0;i < h;i++) {
		for (int j = 0;j < w;j++) {
			cin >> a[i][j];
			if (a[i][j] == '#') {
				count++;
			}
		}
	}

	if (search(0, 0) && count == h + w - 1) {
		cout << "Possible" << endl;
	}
	else {
		cout << "Impossible" << endl;
	}
	return 0;
}