#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<iomanip>

using namespace std;

int main(void) {
	int h, w;
	cin >> h >> w;
	vector<string>A(h);
	int step = 0;
	for (int i = 0; i < h; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (A[i][j] == '#') {
				step++;
			}
		}
	}
	if (step == h + w - 1) {
		cout << "Possible";
	}
	else {
		cout << "Impossible";
	}

	return 0;
}