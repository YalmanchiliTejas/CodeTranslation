#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<regex>
#include<ctype.h>
using namespace std;

int main(void) {
	int h, w;
	char a[100][100];
	int ck_h[100] = {}, ck_w[100] = {};
	cin >> h >> w;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
			if (a[i][j] == '#') {
				ck_h[i] = 1;
				ck_w[j] = 1;
			}
		}
	}

	for (int i = 0; i < h; i++) {
		int ln = 0;
		for (int j = 0; j < w; j++) {	
			if (ck_h[i] != 0 && ck_w[j] != 0) {
				cout << a[i][j] << flush;
				ln = 1;
			}
		}
		if (ln == 1) cout << endl;
	}

	return 0;
}