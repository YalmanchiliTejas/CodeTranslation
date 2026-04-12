#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int h, w;
	string a[100];

	cin >> h >> w;
	for (int i = 0; i < h; i++) cin >> a[i];

	//列削除
	int wcnt = 0;
	for (int j = 0; a[0][j] != '\0'; j++) {
		if (a[0][j] == '.') {
			bool flg = true;
			for (int i = 1; i < h; i++) {
				if (a[i][j] == '#') flg = false;
			}
			if (flg == true) {
				for (int i = 0; i < h; i++) a[i].erase(a[i].begin() + j);
				wcnt++;
				j--;
			}
		}
	}

	//行削除
	int hcnt = 0;
	string white(w - wcnt, '.');
	for (int i = 0; i < h; i++) {
		if (a[i] == white) {
			a[i].clear();
			hcnt++;
		}
	}

	for (int i = 0; i < h; i++) {
		if (a[i][0] != '\0') {
			cout << a[i] << endl;
		}
	}

	return 0;
}