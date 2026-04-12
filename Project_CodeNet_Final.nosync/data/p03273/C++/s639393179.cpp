#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <bitset>
using namespace std;
const int INF = 0xfffffff;

int main()
{
	int h, w;
	cin >> h >> w;
	int first[105][105] = { 0 };
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			char a;
			cin >> a;
			if (a == '#') first[i][j] = 1;
		}
	}
	int second[105][105] = { 0 };
	int newh = h, newi = 0;;
	for (int i = 0; i < h; i++) {
		bool flag = true;
		for (int j = 0; j < w; j++) {
			if (first[i][j] == 1) {
				flag = false;
				second[newi][j] = 1;
			}
		}
		if (!flag) newi++;
		if (flag) newh--;
	}

	int third[105][105] = { 0 };
	int neww = w;
	newi = 0;
	for (int i = 0; i < w; i++) {
		bool flag = true;
		for (int j = 0; j < newh; j++) {
			if (second[j][i] == 1) {
				flag = false;
				third[j][newi] = 1;
			}
		}
		if (!flag) newi++;
		if (flag) neww--;
	}

	for (int i = 0; i < newh; i++) {
		for (int j = 0; j < neww; j++) {
			if (third[i][j] == 1) cout << '#';
			else cout << '.';
		}
		cout << endl;
	}
    return 0;
}

