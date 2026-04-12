#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
	int h,w;
	cin>>h>>w;
	vector<vector<char>> a(h,vector<char>(w));
	for (int i=0;i<h;i++) {
		for (int j=0;j<w;j++) {
			cin>>a[i][j];
		}
	}
	vector<int>hc(h),wc(w);
	for (int i=0;i<h;i++) {
		for (int j=0;j<w;j++) {
			if(a[i][j] == '#')break;
			else if(a[i][j] == '.') {
				if (j == w-1) hc[i]++;
			}
		}
	}
	for (int i=0;i<w;i++) {
		for (int j=0;j<h;j++) {
			if(a[j][i] == '#')break;
			else if(a[j][i] == '.') {
				if (j == h-1) wc[i]++;
			}
		}
	}

	for (int i=0;i<h;i++) {
		if (!hc[i]) {
			for (int j=0;j<w;j++) {
				if (!wc[j]) cout << a[i][j];
				if (j == w-1) cout << endl;
			}
		}
	}
	

}
