#include <iostream>
#include <string>
#include <vector>

using namespace std;

int drow[] = { -1, 0, 1, 0 };
int dcolumn[] = { 0, -1, 0, 1 };

int main() {
	int h, w;
	vector<string> m;

	cin >> h >> w;

	m.resize(h);
	for (int i = 0; i < h; i++) {
		cin >> m[i];
	}

	string result = "Possible";

	int i = 0;
	int j = 0;

	if (m[i][j] == '.') {
		result = "Impossible";
	}
	else {
		m[i][j] = '$';
	}

	while (result == "Possible" && (i != h - 1 || j != w - 1)) {
		int total = 0;
		int ni = i;
		int nj = j;
		for (int k = 0; k < 4; k++) {
			int ci = i + drow[k];
			int cj = j + dcolumn[k];

			if (ci > -1 && ci < h && cj > -1 && cj < w && m[ci][cj] == '#') {
				total++;
				ni = ci;
				nj = cj;
			}
		}

		if (total != 1 || ni < i || nj < j) {
			result = "Impossible";
		}
		else {
			i = ni;
			j = nj;
			m[i][j] = '$';
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (m[i][j] == '#') {
				result = "Impossible";
			}
		}
	}

	cout << result << "\n";

	return 0;
}