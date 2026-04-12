#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
int main() {
	int H, W;	cin >> H >> W;
	vector<string> A(H);
	int num = 0;
	for (int i = 0; i < H; ++i) {
		cin >> A[i];
		for (int j = 0; j < W; ++j)if (A[i][j] == '#')++num;
	}
	if (num == H + W - 1)cout << "Possible" << endl;
	else cout << "Impossible" << endl;
}