#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int H, W;
	cin >> H >> W;
	vector<vector<char>> R(H, vector<char>(W));

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> R.at(i).at(j);
		}
	}

	int k;
	for (int i = 0; i < H; i++) {
		k = 0;
		for (int j = 0; j < W; j++) {
			if (R.at(i).at(j) == '.') {
				k++;
			}
			else {
				break;
			}
		}
		if (k == W) {
			R.erase(R.begin() + i);
			H--;
			i--;
		}
	}


	for (int i = 0; i < W; i++) {
		int k = 0;
		for (int j = 0; j < H; j++) {
			if (R.at(j).at(i) == '.') {
				k++;
			}
			else {
				break;
			}
		}
		if (k == H) {
			for (int j = 0; j < H; j++) {
				R.at(j).erase(R.at(j).begin() + i);
			}
			W--;
			i--;
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << R.at(i).at(j);
		}
		cout << endl;
	}
}