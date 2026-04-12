#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
#include<vector>
 
using namespace std;
 
int main() {
	int h,w;
	cin >> h >> w;
	vector<string> a(h+10);
	for (int i = 0; i < h; i++) {
		cin >> a[i];
	}
	vector<bool> x(h+10, false);
	vector<bool> y(w+10, false);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j] == '#') {
				x[i] = true;
				y[j] = true;
			}
		}
	}
 
	for (int i = 0; i < h; i++) {
		if (x[i]) {
			for (int j = 0; j < w; j++) {
				if (y[j]) 
					cout << a[i][j];
			}
			cout << endl;
		}
	}
}