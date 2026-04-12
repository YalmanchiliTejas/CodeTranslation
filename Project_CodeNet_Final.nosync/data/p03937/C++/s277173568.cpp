#include <iostream>
#include <string>

using namespace std;

int main() {
	int h,w;

	cin >> h >> w;

	int xpos = 0;

	for (int i = 0; i < h; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < xpos; j++) {
			if (s.at(j) == '#') {
				cout << "Impossible" << endl;
				return 0;
			}
		}
		if (s.at(xpos) == '.') {
			cout << "Impossible" << endl;
			return 0;
		}
		while(xpos + 1 < w && s.at(xpos+1) == '#') {
			xpos++;
		}
		for (int j = xpos + 1; j < w; j++) {
			if (s.at(j) == '#') {
				cout << "Impossible" << endl;
				return 0;
			}
		}

	}
	if (xpos != w - 1) {
		cout << "Impossible" << endl;
		return 0;
	} 
	cout << "Possible" << endl;

	return 0;

}