#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<vector>
#include<cstdio>

using namespace std;
/*
int find(int x, vector<int> &p) {
if (p[x] == x)return x;
return p[x] = find(p[x], p);
}

void uni(int x, int y, vector<int> &p) {
x = find(x, p);
y = find(y, p);
p[x] = y;
}

int same(int x, int y, vector<int> p) {
if (find(x, p) == find(y, p))return 1;
return 0;
}
*/

//long long a[1002];


int main()
{
	long long N, cnt = 0, tmp, ans = 0;
	long long H, W;
	cin >> H >> W;
	vector<vector<int>> a = vector<vector<int>>(H, vector<int>(W, 0));
	vector<bool> fh(H, true), fw(W, true);
	char c;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> c;
			if (c == '#') {
				a[i][j] = 1;
				fh[i] = false;
			}
		}
	}


	for (int j = 0; j < W; j++) {
		for (int i = 0; i < H; i++) {
			if (a[i][j] == 1) {
				fw[j] = false;
			}
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (fw[j] == false && fh[i] == false) {
				if (a[i][j] == 0) {
					cout << '.';
				}
				else {
					cout << '#';
				}
			}
		}
		if(fh[i] == false)cout << endl;
	}


	char qq;
	cin >> qq;
	return 0;
}