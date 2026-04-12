#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int H, W;
	cin >> H >> W;
	char a[100][100];
	vector<bool>tmp(H, false);
	vector<bool>row(W, false);
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++) {
			cin >> a[i][j];
			if (a[i][j] == '#') {
				tmp[i] = true;
				row[j] = true;
			}
		}
	}

	for (int i = 0; i < H; i++)
	{
		if (tmp[i]) {
			for (int j = 0; j < W; j++) {
				if (row[j]) {
					cout << a[i][j];
				}
			}
			cout << endl;
		}
	}
	return 0;
}