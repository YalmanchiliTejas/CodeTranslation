#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<string.h>
#include<complex>
#include<math.h>
using namespace std;
typedef long long int llint;
#define rep(i,n) for(int i=0;i<n;i++)

bool check(int a, int b) {
	return a > b;
}

int main() {
	int h, w;
	cin >> h >> w;
	char s[10][10];
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
