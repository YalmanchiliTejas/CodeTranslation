#include <iostream>
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	bool col[w];
	bool row[h];
	char hw[h][w];
	char ret[h][w];
	for(int i = 0; i < w; i++) {
		col[i] = false;
	}
	for(int i = 0; i < h; i++) {
		row[i] = false;
	}
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			cin >> hw[i][j];
		}
	}
	for(int i = 0; i < h; i++) {
		row[i] = false;
		for(int j = 0; j < w; j++) {
			char v = hw[i][j];
			if(v == '#') {
				col[j] = true;
				row[i] = true;
			}
		}
	}
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			if(col[j] && row[i]) cout << hw[i][j];
		}
		if(row[i]) cout << endl;
	}
	return 0;
}
