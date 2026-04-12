#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	int r = a % b;
	return gcd(b, r);
}
int main(){
	int h, w;
	cin >> h >> w;
	vector<string> mo(h);
	vector<vector<int>> a(h, vector<int>(w,1));
	vector<vector<int>> b(w, vector<int>(h,1));
	vector<int> eh(h,0);
	vector<int> ew(w,0);
	for (int i = 0; i < h; i++) {
		string s;
		cin >> s;
		mo[i]=s;
		for (int j = 0; j < w; j++) {
			if (s[j] == '.') {
				a[i][j] = 0;
				b[j][i] = 0;
			}
		}
	}
	vector<int> zh(w, 0);
	vector<int> zw(h, 0);
	for (int i = 0; i < h; i++) {
		if (a[i] == zh) {
			eh[i] = 1;
		}
	}
	for (int i = 0; i < w; i++) {
		if (b[i] == zw) {
			ew[i] = 1;
		}
	}
	for (int i = 0; i < h; i++) {
		if (eh[i] == 0) {
			for (int j = 0; j < w; j++) {
				if (ew[j] == 0) {
					cout << mo[i][j];
				}
			}
			cout << endl;
		}
	}
}