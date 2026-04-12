#include <iostream>
#include <string>
using namespace std;
typedef signed long long ll;
char grid[100][100];
bool goodr[107], goodc[107];
int main() {
	int r, c; cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> grid[i][j];
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (grid[i][j] == '#') {
				goodr[i] = true;
				goodc[j] = true;
			}
		}
	}
	for (int i = 0; i < r; i++) {
		if (goodr[i]) {
			for (int j = 0; j < c; j++) {
				if (goodc[j]) {
					cout << grid[i][j];
				}
			}
			cout << endl;
		}
	}
	
	 return 0;
}
