#include<bits/stdc++.h>
using namespace std;
const int N(11);
char s[N][N];
int main() {
	int h, w;
	cin >> h >> w;
	int tot(0);
	for(int i(0); i < h; i++) {
		cin >> s[i];
		for(int j(0); j < w; j++) {
			tot += s[i][j] == '#';
		}
	}
	bool posi(false);
	for(int msk(0); msk < (1 << (h - 1 + w - 1)); msk++) {
		int cnt(0);
		int x(0), y(0);
		if(s[x][y] != '#') {
			continue;
		}
		cnt = 1;
		for(int i(0); i < h - 1 + w - 1; i++) {
			if(msk >> i & 1) {
				x += 1;
			}else {
				y += 1;
			}
			if(x >= h || y >= w || s[x][y] != '#') {
				cnt = -1;
				break;
			}
			cnt += 1;
		}
		if(cnt == tot) {
			posi = true;
			break;
		}
	}
	printf("%s\n", posi ? "Possible" : "Impossible");
}
