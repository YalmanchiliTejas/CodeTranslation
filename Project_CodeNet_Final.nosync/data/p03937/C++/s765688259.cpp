#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<vector>
#include<utility>
#define FOR(i, a, b) for(int i=(a);i<=(b);i++)
#define RFOR(i, a, b) for(int i=(a);i>=(b);i--)
#define MOD 1000000007
using namespace std;

int main(void) {
	int h, w;
	int count = 0;
	char a[9][9];
	cin >> h >> w;
	FOR(i, 1, h) {
		FOR(t, 1, w) {
			cin >> a[i][t];
			if (a[i][t] == '#') {
				count++;
			}
		}
	}
	if (count == h + w - 1) {
		cout << "Possible" << endl;
	}
	else {
		cout << "Impossible" << endl;
	}
	
	return 0;
}