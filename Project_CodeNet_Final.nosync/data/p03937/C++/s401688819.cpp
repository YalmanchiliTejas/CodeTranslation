#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int a[10][10], H, W, cnt;
int main() {
	cin >> H >> W;
	for (int i = 0; i < H; i++) { for (int j = 0; j < W; j++) { char p; cin >> p; if (p == '#')cnt++; } }
	if (cnt == H + W - 1) { cout << "Possible" << endl; }
	else { cout << "Impossible" << endl; }
	return 0;
}