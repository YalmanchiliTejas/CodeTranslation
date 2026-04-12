#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>

#define rep(i,a,b) for(long long i=a;i<b;i++)

using namespace std;


int main(void) {

	long long N = 0, K = 0, H = 0, W = 0, C = 0;
	char a[100][100] = {};
	int b[100] = {};
	long long c[300] = { 0 };
	long long d[300] = { 0 };
	//long long y[20] = {};
	string s;
	
	long long min = 0, min2 = 0;
	long long dif = 0;
	long long hoge = 0;
	long long sum = 0;
	long long up = 0;

	cin >> H >> W;

	rep(j, 0, H) {
		rep(i, 0, W) {
			cin >> a[i][j];
		}
	}

	rep(j, 0, H) {
		rep(i, 0, W) {

			if (a[i][j] == '#' || a[i][j] == '\0') {
				break;
			}
			else {
				sum++;
			}


		}

		if (sum == W) {
			b[j] = 1;
		}
		sum = 0;
	}


	

	rep(i, 0, W) {
		rep(j, 0,H) {

			if (a[i][j] == '#' || a[i][j] == '\0') {
				break;
			}
			else {
				sum++;
			}


		}

		if (sum == H) {
			c[i] = 1;
		}
		sum = 0;
	}

	/*rep(i, 0, W) {

		cout << c[i];
	}
*/

	rep(j, 0, H) {

		if (b[j] == 0) {
			rep(i, 0, W) {
				if (c[i] == 0)
					cout << a[i][j];
			}
			cout << endl;
		}
	}
	
	return 0;

}

