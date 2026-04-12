#include <iostream>
#include <vector>
using namespace std;

int main() {
	int H, W;
	cin >> H >> W;
	vector<int> a_row(W, 0);//0初期化
	vector<vector<int> > a(H, a_row); 
	for (int i=0; i<H; ++i) {
		for (int j=0; j<W; ++j) {
			char c;
			cin >> c;
			// whiteを1とする
			if (c=='.') a[i][j] = 1;
		}
	}
	vector<int> row_index(H,0);
	for (int i=0; i<H; ++i) {
		int is_white = 1;
		for (int j=0; j<W; ++j) {
			is_white *= a[i][j];
		}
		if (is_white == 1) row_index[i] = 1;
	}
	vector<int> col_index(W,0);
	for (int j=0; j<W; ++j) {
		int is_white = 1;
		for (int i=0; i<H; ++i) {
			is_white *= a[i][j];
		}
		if (is_white == 1) col_index[j] = 1;
	}
	for (int i=0; i<H; ++i) {
		if (row_index[i] == 1) continue;
		for (int j=0; j<W; ++j) {
			if (col_index[j] == 1) continue;
			cout << (a[i][j] == 1 ? '.' : '#');
		}
		cout << endl;
	}
	return 0;
}

