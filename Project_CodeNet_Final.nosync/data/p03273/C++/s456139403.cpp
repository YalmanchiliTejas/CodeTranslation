#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int h, w;

	cin >> h >> w ;

	vector<vector<char>> a(h, vector<char>(w));
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
		}
	}

	vector<bool> x(h,false);
	vector<bool> y(w, false);

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j]=='#') {
				x[i] = true;
				y[j] = true;
			}
		}
	}

	for (int i = 0; i < h; i++) {
		if (x[i]) {
			for (int j = 0; j < w; j++) {
				if (y[j]) {
					cout << a[i][j];
				}
			}
			cout << endl;
		}
	}
}