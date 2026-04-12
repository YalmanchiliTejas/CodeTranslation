#include<iostream>

using namespace std;

int main(void) {
	int h, w;
	char a[8][8];
	int total = 0;

	cin >> h >> w;

	for (int i = 0; i < h; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j] == '#') {
				total++;
			}
		}
	}

	if (total == h + w - 1) {
		cout << "Possible" << endl;
	}
	else {
		cout << "Impossible" << endl;
	}

	return 0;
}