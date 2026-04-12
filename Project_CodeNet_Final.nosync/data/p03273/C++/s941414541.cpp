#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int h, w;
	cin >> h >> w;
	vector<vector<char>> map(h, vector<char>(w));

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < h; i++) {
		bool emp = true;
		for (int j = 0; j < w; j++) {
			if (map[i][j] == '#') {
				emp = false;
			}
		}

		if (emp) {
			for (int k = 0; k < w; k++)
				map[i][k] = '*';
		}
	}

	for (int i = 0; i < w; i++) {
		bool emp = true;
		for (int j = 0; j < h; j++) {
			if (map[j][i] == '#') {
				emp = false;
			}
		}

		if (emp) {
			for (int k = 0; k < h; k++) {
				map[k][i] = '*';
			}
		}
	}

	for (int i = 0; i < h; i++) {
		bool a = false;
		for (int j = 0; j < w; j++) {
			
			if (map[i][j] != '*') {
				cout << map[i][j];
				a = true;
			}
			
		}
		if (a)
		cout << endl;
	}
	

	return 0;
}