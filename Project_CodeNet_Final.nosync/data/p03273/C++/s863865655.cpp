#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int h, w;
	cin >> h >> w;
	vector<vector<char>> v(h, vector<char>(w));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> v[i][j];
		}
	}
	for (int i = h - 1; i >= 0; i--) {
		bool f = true;
		for (int j = 0; j < w; j++) {
			if (v[i][j] == '#') {
				f = false;
				break;
			}
		}
		if (f) {
			v.erase(v.begin() + i);
		}
	}
	h = v.size();

	for (int j = w - 1; j >= 0; j--) {
		bool f = true;
		for (int i = 0; i < h; i++) {
			if (v[i][j] == '#') {
				f = false;
				break;
			}
		}
		if (f) {
			for (int i = 0; i < h; i++) {
				v[i].erase(v[i].begin() + j);
			}
		}
	}
	w = v[0].size();

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << v[i][j];
		}
		cout << endl;
	}
}