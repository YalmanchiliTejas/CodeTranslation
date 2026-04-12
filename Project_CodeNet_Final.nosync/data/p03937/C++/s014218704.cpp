#include <bits/stdc++.h>
using namespace std;

int main() {
	int H, W; cin >> H >> W;
	for (int i = 1, pre = 0; i <= H; ++i) {
		char A[10];
		cin >> A + 1;
		int cnt = 0;
		for (int j = 1; j <= W; ++j) {
			if (A[j] == '#') {
				if (A[j-1] == '.') ++cnt;
				if (pre > j) return !printf("Impossible");
				pre = j;
			}
		}
		if (cnt > 1) return !printf("Impossible");
	}
	printf("Possible");
	return 0;
}