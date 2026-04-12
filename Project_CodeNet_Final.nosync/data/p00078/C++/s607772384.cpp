#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <vector>
#include <cctype>
#include <cstdio>
#include <iomanip>
#include <functional>
#include <stack>
#include <numeric>
#include <utility>
#include <queue>
#define PI 3.1415926535
#define FOR(i,n) for (int i=0; i<(n) ;i++)
#define INF 114514810

using namespace std;

int n, d[15][15], ct, x, y;

int main(){
	while (true){
		FOR(i, n)
			FOR(j, n) d[i][j] = 0;
		ct = 1;
		cin >> n;
		if (n == 0) break;
		x = n / 2; y = n / 2 + 1; //preset
		while (ct <= n*n){
			while (!(0 <= x&&x <= n - 1 && 0 <= y&&y <= n - 1&&d[x][y] == 0)) {
				if (x > n - 1) x = 0;
				if (x < 0) x = n - 1;
				if (y > n - 1) y = 0;
				if (d[x][y] > 0) { x--; y++; }
			}
			d[x][y] = ct;
			ct++; x++; y++;
		}
		FOR(i, n){
			FOR(j, n){
				if (d[j][i] < 10) cout << "   " << d[j][i];
				else if (d[j][i] < 100) cout << "  " << d[j][i];
				else if (d[j][i] < 1000) cout << " " << d[j][i];
			}
			cout << endl;
		}
	}
}