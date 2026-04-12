#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

int main() {
	int h, w;
	char a[100][100];
	int i, j;
	char x;
	vector<int> hi, wj;

	cin >> h >> w;

	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			cin >> x;
			a[i][j] = x;
		}
		hi.push_back(i);
		wj.push_back(i);
	}

	for (i = 0; i < h; i++) {
		if (a[i][0] != '.')
			continue;
		for (j = 1; j < w; j++) {
			if (a[i][j] != '.')
				break;
		}
		if (j == w) {
			hi[i] = -1;
		}
	}
	for (j = 0; j < w; j++) {
		if (a[0][j] != '.')
			continue;
		for (i = 1; i < h; i++) {
			if (a[i][j] != '.')
				break;
		}
		if (i == h) {
			wj[j] = -1;
		}
	}

	for (i = 0; i < h; i++) {
		if (hi[i] == -1)
			continue;
		for (j = 0; j < w; j++) {
			if (wj[j] == -1)
				continue;
			cout << a[i][j];
		}
		cout << endl;
	}

	return 0;
}