#include <bits/stdc++.h>
using namespace std;
int main() {
	int h, w;
	scanf("%d%d", &h, &w);
	char c[h][w];
	for (int i = 0; i < h; i++) scanf("%s", c[i]);
	vector<int> cnth(h), cntv(w);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (c[i][j] == '#') cnth[i]++, cntv[j]++;
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (cnth[i] != 0 and cntv[j] != 0) printf("%c", c[i][j]);
		}
		if (cnth[i] != 0) printf("\n");
	}
	return 0;
}