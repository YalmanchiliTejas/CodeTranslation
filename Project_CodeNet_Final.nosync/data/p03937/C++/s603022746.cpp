#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <functional>
#include <algorithm>
#include <complex>
#include <map>
#include <cmath>
#include <string>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <istream>
//------------------------------------define------------------------//
#define PB push_buck
#define MP make_pair
//------------------------------------typedef-----------------------//
typedef long long ll;

using namespace std;

int h,w;
char a[1000000][8];
int sum = 0;
//--------------------------------------------------------------//
int main() {
	cin >> h >> w;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j] == '#') {
				sum++;
				if (a[i - 1][j] != '#' && a[i][j - 1] != '#' && i != 0 && j != 0 ) {
					cout << "Impossible" << endl;
					return 0;
				}
				else if (i == 0 && j!=0) {
					if (a[0][j - 1] != '#') {
						cout << "Impossible" << endl;
						return 0;
					}
				}
				else if (i != 0 && j == 0) {
					if (a[i - 1][0] != '#') {
						cout << "Impossible" << endl;
						return 0;
					}
				}
			}
		}
	}
	if (sum == h + w - 1 && a[h-1][w-1]=='#' && a[0][0]=='#') {
		cout << "Possible" << endl;
	}
	else {
		cout << "Impossible" << endl;
	}

}