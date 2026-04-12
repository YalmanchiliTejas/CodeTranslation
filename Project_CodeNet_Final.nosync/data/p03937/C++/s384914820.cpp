#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
typedef long long ll;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int H, W;
	char ch;
	cin >> H >> W;
	int i, j;
	int cnt = 0;
	for (i = 0; i < H; i++) {
		for (j = 0; j < W; j++) {
			cin >> ch;
			if (ch == '#')cnt++;
		}
	}
	if (cnt == H + W - 1)cout << "Possible" << endl;
	else cout << "Impossible" << endl;
	return 0;
}