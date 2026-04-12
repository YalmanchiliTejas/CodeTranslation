#include<iostream>
#include<iomanip>
#include<string>
#include<array>
#include<cmath>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;


int main() {
	int h, w;
	string a[110];
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < h; i++) {
		int count = 0;
		for (int j = 0; j < w; j++) {
			if (a[i][j] == '.') {
				count++;
			}
		}
		if (count == w) {
			for (int j = 0; j < w; j++) {
				a[i][j] = '*';
			}
		}
	}
	for (int j = 0; j < w; j++) {
		int count = 0;
		for (int i = 0; i < h; i++) {
			if (a[i][j] != '#') {
				count++;
			}
		}
		if (count == h) {
			for (int i = 0; i < h; i++) {
				a[i][j] = '*';
			}
		}
	}
	for (int i = 0; i < h; i++) {
		int count = 0;
		for (int j = 0; j < w; j++) {
			if (a[i][j] != '*') {
				cout << a[i][j];
				count = 1;
			}
		}
		if (count == 1) {
			cout << endl;
		}
	}
}