#include <iostream>
#include <vector>
using namespace std;
int main() {
	int a, b;
	char k[105][105];
	cin >> a >> b;
	vector<bool>height(a, 0);
	vector<bool>width(b, 0);
	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < b; ++j) {
			cin >> k[i][j];
			if (k[i][j] == '#') {
				height[i] = 1, width[j] = 1;
			}
		}
	}

	for (int i = 0; i < a; ++i) {
		if (height[i]) {
			for (int j = 0; j < b; ++j) {
				if (width[j]) cout << k[i][j];
			}
			cout << endl;
		}
	}
}