#include <string>
#include <iostream>

using namespace std;

int main()
{
	long long ans = 0, i, j, k = 0, H, W, cnt, b[100] = { 0 }, c[100] = { 0 };
	string a[100];

	cin >> H >> W;

	for (i = 0; i < H; i++) {
		cin >> a[i];
	}
	
	for (i = H-1; i >= 0; i--) {
		cnt = 0;
		for (j = 0; j < W; j++) {
			if (a[i][j] == '.') {
				cnt++;
				c[j]++;
			}
		}
		if (cnt == W) {
			b[i]++;
		}
	}

	cnt = 0;
	for (j = W - 1; j >= 0; j--) {
		if (c[j] == H) {
			for (i = 0; i < H; i++) {
				a[i].erase(a[i].begin() + j);
			}
			cnt++;
		}

	}

	for (i = 0; i < H; i++) {
		if(b[i]==0)
		cout << a[i] << endl;
	}

	return 0;
}