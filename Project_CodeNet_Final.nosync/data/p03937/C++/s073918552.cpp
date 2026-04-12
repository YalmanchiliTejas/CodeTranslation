#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> P;

int main() {
	int h, w;
	cin >> h >> w;
	vector< vector<char> > hyo(h, vector<char>(w));
	vector< vector<int> > hh(h, vector<int>(w, 1));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> hyo[i][j];
		}
	}
	queue<P> q;
	q.push(P(0, 0));
	hyo[0][0] = '.';

	while(!q.empty()) {
		P p = q.front();
		q.pop();
		if (p.first+1 < h) {
			if (p.second+1 < w) {
				if (hyo[p.first+1][p.second] == '#') {
					q.push(P(p.first+1, p.second));
					hyo[p.first+1][p.second] = '.';
				} else if (hyo[p.first][p.second+1] == '#') {
					q.push(P(p.first, p.second+1));
					hyo[p.first][p.second+1] = '.';
				}
			} else {
				if (hyo[p.first+1][p.second] == '#') {
					q.push(P(p.first+1, p.second));
					hyo[p.first+1][p.second] = '.';
				}
			}
		} else {
			if (p.second+1 < w) {
				if (hyo[p.first][p.second+1] == '#') {
					q.push(P(p.first, p.second+1));
					hyo[p.first][p.second+1] = '.';
				}
			} else {
			}
		}
	}
	bool hhh = true;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (hyo[i][j] == '#') {
				hhh = false;
				break;
			}
		}
	}
	if (hhh) {
		cout << "Possible" << endl;
	} else {
		cout << "Impossible" << endl;
	}
	return 0;
}