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
	string a[110];
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		cin >> a[i];
	}
	int t[110] = { 0 };
	int y[110] = { 0 };
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (a[i][j] == '#') {
				t[j]++;
				y[i]++;
			}
		}
	}
	for (int i = 0; i < H; i++) {
		if (y[i] != 0) {
			for (int j = 0; j < W; j++) {
				if (t[j] != 0) {
					cout << a[i][j];
				}
			}
			cout << endl;
		}
	}
}
