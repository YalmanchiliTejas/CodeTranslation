#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
	int h, w;
	cin >> h >> w;

	char hw[h][w];
	string input;

	for (auto i = 0; i < h; i++) {
		cin >> input;
		for (auto j = 0; j < w; j++) {
			hw[i][j] = input[j];
		}
	}

	bool tume1[h] = {};
	bool tume2[w] = {};

	for (auto i = 0; i < h; i++) {
		for (auto j = 0; j < w; j++) {
			if (hw[i][j] == '#') {
				tume1[i] = true;
				tume2[j] = true;
			}
		}
	}

	//output
	for (auto i = 0; i < h; i++) {
		if (tume1[i] == false) continue;
		for (auto j = 0; j < w; j++) {
			if (tume2[j] == false) continue;
			cout << hw[i][j];
		}
		cout << endl;
	}

	return 0;
}