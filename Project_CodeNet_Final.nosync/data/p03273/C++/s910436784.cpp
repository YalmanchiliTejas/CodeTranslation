#include<iostream>
using namespace std;
int main() {
	int H, W;
	cin >> H >> W;
	bool goodh[110], goodw[110];

	char a[110][110];
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			cin >> a[i][j];
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			if (a[i][j] == '#') {
				goodh[i] = true;
				goodw[j] = true;
			}
	for (int i = 0; i < H; i++)
		if (goodh[i]) {
			for (int j = 0; j < W; j++)
				if (goodw[j])
					cout << a[i][j];
			cout << endl;
		}
	return 0;
}

