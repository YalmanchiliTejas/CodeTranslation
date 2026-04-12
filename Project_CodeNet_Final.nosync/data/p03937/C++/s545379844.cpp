#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	vector<string>s(h);
	for (int i = 0; i < h; i++) {
		cin >> s[i];
	}
	int count = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (s[i][j] == '#') {
				count++;
			}
		}
	}
	if (count == h + w - 1) {
		cout << "Possible" << endl;
	}
	else
		cout << "Impossible" << endl;
}
	

