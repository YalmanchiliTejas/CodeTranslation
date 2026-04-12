#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<iomanip>

#define INF 1<<29

using namespace std;

//白いとこを消すのではなく、黒いとこを表示するととらえる。完コピ

int main(void) {
	int h, w;
	cin >> h >> w;
	vector<string>a(h);
	for (int i = 0; i < h; i++) {
		cin >> a[i];
	}
	vector<bool>row(h, false), col(w, false);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j] == '#') {
				row[i] = true;
				col[j] = true;
			}
		}
	}
	for (int i = 0; i < h; i++) {
		if (row[i]) {
			for (int j = 0; j < w; j++) {
				if (col[j]) {
					cout << a[i][j];
				}
			}
			cout << endl;
		}
	}
	return 0;
}