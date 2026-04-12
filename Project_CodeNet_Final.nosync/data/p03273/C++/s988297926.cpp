#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
typedef long long ll;
using namespace std;
char a[100][100];



int main(void) {
	int h, w;
	cin >> h >> w;
	int num = 0;
	bool can = true;
	for (int i = 0;i < h;i++) {
		for (int j = 0;j < w;j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0;i < h;i++) {
		num = 0;
		for (int j = 0;j < w;j++) {
			if (a[i][j] == '.')num++;
		}
		if (num == w) {
			for (int k = 0;k < w;k++)a[i][k] = ' ';
		}
	}
	for (int i = 0;i < w;i++) {
		can = true;
		for (int j = 0;j < h;j++) {
			if (a[j][i] == '#') {
				can = false;
				break;
			}
		}
		if (can) {
			for (int k = 0;k < h;k++)a[k][i] = ' ';
		}
	}
	num = 0;
	for (int i = 0;i < h;i++) {
		num = 0;
		for (int j = 0;j < w;j++) {
			if (a[i][j] != ' ')cout << a[i][j];
			else num++;
		}
		if(num!=w)cout << endl;
	}
	return 0;
}