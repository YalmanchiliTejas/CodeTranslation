#include <iostream>
using namespace std;

int fail() {
	cout << "Impossible" << endl;
	return 0;
}

int main() {
	int H, W, minj, maxj, prevLast = 0;
	bool pos = true;
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		string l;
		bool found = 0;
		int first, last, cnt = 0;
		cin >> l;
		for (int j = 0; j < W; j++) {
			if (l[j] == '#') {
				if (!found) {
					if(j < prevLast) return fail();
					found = true;
					first = j;
				}
				cnt++;
				if(first + cnt - 1 < j) return fail();
				last = j;
			}
		}
		prevLast = last;
	}
	cout << "Possible" << endl;
	return 0;
}