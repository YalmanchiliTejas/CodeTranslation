#include<iostream>
#include <string> 
#include <vector>  
#include<math.h>
#include <algorithm>
#include<iomanip>
#define INF 1000000000
#define LM 55555
using namespace::std;


long long n, bc, now, C, H, W, X, Y, ans, r, l, numcon, N, M;
string S,s,a[101],b[101],c[101];
bool h,k[101];
int main() {
	cin >> H>>W;
	Y = 0;
	X = 0;
	for (int i = 0; i <H;i++) {
		cin >> a[i];
	}

	for (int i = 0; i < H; i++) {
		h = false;
		for (int j = 0; j < W; j++) {
			if (a[i][j] == '#') {
				h = true;
			}
		}
		if (h == true) {
			b[Y] += a[i];
			Y++;
		}
	}

	for (int i = 0; i < W; i++) {
		k[i] = true;
	}

	for (int j = 0; j < W; j++) {
		for (int i = 0; i < Y; i++) {
			if (b[i][j] == '#'&&k[j]==true) {
				k[j] = false;
			}
			
			}
		}

	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < W; j++) {
			if (k[j] == false) {
				cout << b[i][j];
			  }
			}
		cout<< endl;
		}

	return 0;

}


