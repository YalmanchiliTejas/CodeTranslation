#include <iostream>
#include <string>

using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	int k = 0;
	for (int j = 0; j < h; ++j) {
		string line;
		cin >> line;
		for (int i = 0; i < w; ++i) {
			if (line[i] == '#') {
				if (i < k) {
					cout << "Impossible" << endl;
					goto end;
				} else {
					k = i;
				}
			}
		}
	}
	cout << "Possible" << endl;
end:
	return 0;
}