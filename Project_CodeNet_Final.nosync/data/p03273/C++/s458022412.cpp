#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include<stdio.h>
#include <functional>
#include<algorithm>
#define PI 3.14159265
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n)  FOR(i,0,n)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define SZ(x) ((int)(x).size())

using namespace std;



int main() {
	int h, w;
	cin >> h >> w;
	int hw[100][100];
	string s;
	REP(i, h) {
		cin >> s;
		REP(j, w) {
			
			if (s[j] == '.') {
				hw[i][j] = 0;
			}
			else {
				hw[i][j] = 1;
			}
		}
	}
	//while (1) {
		REP(i, h) {
			REP(j, w) {
				if (hw[i][j] == 1) break;
				if (j == w - 1) {
					REP(k, w) {
						hw[i][k] = -1;
					}
				}
			}

		}
		REP(i, w) {
			REP(j, h) {
				if (hw[j][i] == 1) break;
				if (j == h - 1) {
					REP(k, h) {
						hw[k][i] = -1;
					}
				}
			}

		}
	//}
		int flag;
	REP(i, h) {
		flag = 0;
		REP(j, w) {
			
				if (hw[i][j]==1) {
					cout << "#";
					flag = 1;
				}
				else if (hw[i][j] == 0) {
					cout << ".";
					flag = 1;
				}
				
			
		}
		if (flag == 1) {
			cout << endl;
		}
		
	}
	return 0;
}