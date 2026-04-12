#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
using namespace std;
typedef vector<int> vi;


int main() {
	int w, h;
	cin >> h >> w;
	char bd[8][8];
	for (int i = 0; i < h; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < w; j++) {
			bd[i][j] = s[j];
		}
	}
	int count = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (bd[i][j] == '#')count++;
		}
	}
	if (count != w + h - 1) {
		cout << "Impossible" << endl;
		return 0;
	}

	int ans[8][8];
	memset(ans, 0, sizeof(ans));
	ans[0][0] = 1;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (bd[i][j] == '#') {
				if (i > 0 && ans[i - 1][j] == 1 || j > 0 && ans[i][j - 1] == 1) {
					ans[i][j] = 1;
				}
			}
		}
	}
	if (ans[h - 1][w - 1] == 1) {
		cout << "Possible" << endl;

	}
	else {
		cout << "Impossible" << endl;
	}
	return 0;
}

