#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include<numeric>
#include<iomanip>
using namespace std;

int main()
{
	int h, w; cin >> h>>w;
	vector<string>a(h);
	for (int i = 0; i < h; i++) {
		cin >> a[i];
	}
	int count = 0;
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			if (a[j][i] == '.') {
				count++;
			}
			if (count == h) {
				for (int n = 0; n < h; n++) {
					a[n].erase(i, 1);
				}
				i--; w--;
			}
		}
		count = 0;
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j] == '.') {
				count++;
			}
			if (count == w) {
				a[i].erase(0, a[i].length());
			}
		}
		count = 0;
	}

	for (int i = 0; i < h; i++) {
		if (a[i].length() != 0) {
			cout << a[i] << endl;
		}
	}
}


