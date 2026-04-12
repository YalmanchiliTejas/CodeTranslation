#include <iostream>
#include <vector>

using namespace std;

int main() {
	int h, w;
	char a;
	int count = 0;

	cin >> h >> w;

	for (int i = 0; i < h * w; i++) {
		cin >> a;
		if (a == '#') {
			count++;
		}
	}

	if (count == (h + w - 1)) {
		cout << "Possible" << endl;
	}
	else {
		cout << "Impossible" << endl;
	}

	return 0;
}
