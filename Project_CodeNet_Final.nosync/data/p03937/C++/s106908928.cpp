#include<iostream>
#include<vector>
#include<algorithm>
#include<complex>
#include<string>
#include<string.h>
using namespace std;
typedef long long int llint;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
	int h, w;
	char s[9][9];
	cin >> h >> w;
	rep(i, h) {
		cin >> s[i];
	}
	int cnt = 0;
	rep(i, h) {
		rep(j, w) {
			if (s[i][j] == '#') {
				cnt++;
			}
		}
	}
	if (cnt == h + w - 1) {
		cout << "Possible" << endl;
	}
	else {
		cout << "Impossible" << endl;
	}
	return 0;
}