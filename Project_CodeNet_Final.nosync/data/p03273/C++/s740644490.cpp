#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main()
{
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	
	for (int i = 0; i < h; i++) {
		cin >> s[i];
	}
	set<int> hh, ww;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (s[i][j] == '#') {
				hh.insert(i);
				ww.insert(j);
			}
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (hh.find(i) != hh.end() && ww.find(j) != ww.end()) {
				cout << s[i][j];
			}
		}
		if (hh.find(i) != hh.end()) {
			cout << endl;
		}
	}

	return 0;
}