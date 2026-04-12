#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<stdio.h>
using namespace std;
 
#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define INF 1<<25
 
int main()
{
	char s[100][100];
	int i, j;
	int H, W;
	cin >> H >> W;
	rep(i, H) {
		rep(j, W) {
			cin >> s[i][j];
		}
	}
	rep(j, W) {
		int f = 1;
		rep(i, H) {
			if (s[i][j] == '#') {
				f = 0;
				break;
			}
		}
		if (f) {
			rep(i, H) {
				s[i][j] = 0;
			}
		}
	}
	rep(i, H) {
		int f = 1;
		rep(j, W) {
			if (s[i][j] == '#') {
				f = 0;
				break;
			}
		}
		if (f) {
			rep(j, W) {
				s[i][j] = 0;
			}
		}
	}
	rep(i, H) {
		int f = 0;
		rep(j, W) {
			if (s[i][j] != 0) {
				cout << s[i][j];
				f = 1;
			}
		}
		if (f) cout << endl;
	}
	return 0;
}