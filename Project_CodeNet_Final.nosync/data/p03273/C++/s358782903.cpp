#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<char>>data(h, vector<char>(w));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> data[i][j];
		}
	}

	vector<bool>row(h, false);
	vector<bool>col(w, false);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (data[i][j]=='#') {
				row[i] = true;
				col[j] = true;
			}
		}
	}

	for (int i = 0; i < h; i++) {
		if (row[i]) {
			for (int j = 0; j < w; j++) {
				if (col[j])cout << data[i][j];
			}
			cout << endl;
		}
	}
}