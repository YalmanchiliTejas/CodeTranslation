#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {
	int h, w;
	cin >> h >> w;

	vector<string> data(h);


	for (int i = 0; i < h; i++) {
			cin >> data[i];		
	}


	vector<bool> row(h, false);
	vector<bool> col(w, false);

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (data[i][j] == '#') {
				row[i] = true;
				col[j] = true;
			}
		}
	}


	for (int i = 0; i < h; i++) {
		if (row[i]) {
			for (int j = 0; j < w; j++) {
				if (col[j]) {
					cout << data[i][j];
				}
			}
		}

		cout << endl;
	}
}