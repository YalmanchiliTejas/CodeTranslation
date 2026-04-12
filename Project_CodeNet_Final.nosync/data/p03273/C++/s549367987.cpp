#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int h, w, flag = 0,count = 0;

	cin >> h >> w;
	vector<vector<char>> vec(h, vector<char>(w));

	for (int i = 0; i < h; i++) {
		flag = 0;
		for (int j = 0; j < w; j++) {

			cin >> vec.at(i).at(j);

			if (vec.at(i).at(j) == '#') flag = 1;
			if (j == w - 1 && flag == 0){

				for (int j = 0; j < w; j++) {
					vec.at(i).at(j) = '0';
				}
			}
		}
	}

	for (int i = 0; i < w; i++) {
		flag = 0;
		for (int j = 0; j < h; j++) {
			if (vec.at(j).at(i) == '#') flag = 1;
			if (j == h - 1 && flag == 0) {

				for (int j = 0; j < h; j++) {
					vec.at(j).at(i) = '0';
				}
			}
		}
	}

	for (int i = 0; i < h; i++) {
		flag = 0;
		count = 0;
		for (int j = 0; j < w; j++) {
			if (vec.at(i).at(j) != '0') cout << vec.at(i).at(j);
			else count++;
		}
		if (count != w)cout << endl;
	}
	return 0;
}
