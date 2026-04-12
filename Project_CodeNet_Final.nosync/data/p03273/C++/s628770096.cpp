#include <iostream>
#include <vector>
#include<map>
#include<string>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<typeinfo>
#include<queue>
using namespace std;
int main() {
	int H, W;
	cin >> H >> W;
	vector<string> a(H);
	vector<bool> whitex(W, true);
	vector<bool> whitey(H, true);
	vector<int>colomn, raw;
	for (int i = 0; i < H; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (a[i][j] == '#'){
				whitex[j] = false;
				whitey[i] = false;
				}

		}
	}
	for (int i = 0; i < H; i++) {
		if (whitey[i])raw.push_back(i);
	}
	for (int j = 0; j < W; j++) {
		if (whitex[j])colomn.push_back(j);
	}
	for (int k = 0; k < raw.size(); k++) {
		for (int j = 0; j < W; j++) {
			a[raw[k]][j]='0';
		}
	}
	for (int k = 0; k <colomn.size(); k++) {
		for (int i = 0; i < H; i++) {
			a[i][colomn[k]]='0';
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (a[i][j] != '0') {
				cout << a[i][j];
			}
		}
		int flag = false;
		for (int j = 0; j < W; j++) {
			if (a[i][j] != '0') {
				flag = true;
			}
		}
		if (flag) {
			cout << endl;
		}
	}
}