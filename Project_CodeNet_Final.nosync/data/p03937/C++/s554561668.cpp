#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
const int mod = 1000000007;
#define ll long long

int main()
{
	int H, W;
	string A[10];
	cin >> H >> W;
	int count = 0;
	for (int i = 0; i < H; i++) cin >> A[i];
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (A[i][j] == '#') {
				count++;
			}
		}
	}
	if (count == H + W - 1) cout << "Possible" << endl;
	else cout << "Impossible" << endl;
}