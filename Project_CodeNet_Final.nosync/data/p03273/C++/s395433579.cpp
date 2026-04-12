#include <bits/stdc++.h>
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<char>>a(h, vector<char>(w));
	for (size_t i = 0; i < h; i++) {
		for (size_t j = 0; j < w; j++)cin >> a.at(i).at(j);
	}
	vector<int>fh, fw;
	for (int i = 0; i < h; i++) {
		bool f = false;
		for (int j = 0; j < w; j++) {
			if (a.at(i).at(j) == '#')f = true;
		}
		if (f == false)fh.push_back(i);
	}
	for (int i = 0; i < w; i++) {
		bool f = false;
		for (int j = 0; j < h; j++) {
			if (a.at(j).at(i) == '#')f = true;
		}
		if (f == false)fw.push_back(i);
	}
	for (int i = 0; i < h; i++) {
		if (count(fh.begin(), fh.end(), i))continue;
		else {
			for (int j = 0; j < w; j++) {
				if (count(fw.begin(), fw.end(), j))continue;
				else cout << a.at(i).at(j);
			}
			cout << endl;
		}
	}
}