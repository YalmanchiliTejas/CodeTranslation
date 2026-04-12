#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<bitset>
using namespace std;

int main() {

	int H, W;
	cin >> H >> W;

	vector<string> row;
	vector<string> column(W, "");

	string str;

	for (int i = 0; i < H; i++) {
		cin >> str;
		if (str.find('#', 0) == string::npos) {
			continue;
		}
		else {
			row.push_back(str);
			for (int j = 0; j < W; j++) {
				column[j] += str.substr(j, 1);
			}
		}
	}

	for (int j = W - 1; j >= 0; j--) {
		if (column[j].find('#', 0) == string::npos) {
			for (int i = 0; i < row.size(); i++) {
				row[i].erase(j,1);
			}
		}
	}

	for (int i = 0; i < row.size(); i++) {
		cout << row[i] << endl;
	}

	return 0;
}

