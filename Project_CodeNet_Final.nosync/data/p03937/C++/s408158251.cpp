#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	size_t H, W;
	cin >> H >> W;
	vector<string> A(H + 2);
	for (size_t i = 0; i < W + 2; ++i) {
		if (i == 1) A[0] += '#';
		else A[0] += '.';
	}
	for (size_t i = 1; i <= H; ++i) {
		cin >> A[i];
		A[i] = '.' + A[i] + '.';
	}
	for (size_t i = 0; i < W + 2; ++i) {
		if (i == W) A[H + 1] += '#';
		else A[H + 1] += '.';
	}
	bool ans = true;
	for (size_t i = 1; i <= H; ++i) {
		for (size_t j = 1; j <= W; ++j) {
			if (A[i][j] == '#') {
				int tmp1 = 0, tmp2 = 0;
				if (A[i - 1][j] == '#') ++tmp1;
				if (A[i][j - 1] == '#') ++tmp1;
				if (A[i + 1][j] == '#') ++tmp2;
				if (A[i][j + 1] == '#') ++tmp2;
				if (tmp1 != 1 || tmp2 != 1) ans = false;
			}
		}
	}
	if (ans) cout << "Possible";
	else cout << "Impossible";
}