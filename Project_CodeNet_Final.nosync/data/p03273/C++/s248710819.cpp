//#if 1
//#include"pch.h"
//#define _CRT_SECURE_NO_WARNINGS
//#endif
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<math.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
int main() {

	int H, W;
	char a[120][120];
	int flag[120][120];
	int cnt = 0, f = 0;
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> a[i][j];
			flag[i][j] = 0;
		}
	}
	
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (a[i][j] == '.')cnt++;
		}
		if (cnt == W) {
			for (int j = 0; j < W; j++) {
				flag[i][j] = 1;
			}
		}
		cnt = 0;
	}
	for (int j = 0; j < W; j++) {
		for (int i = 0; i < H; i++) {
			if (a[i][j] == '.')cnt++;
		}
		if (cnt == H) {
			for (int i = 0; i < H; i++) {
				flag[i][j] = 1;
			}
		}
		cnt = 0;
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (flag[i][j] == 0) {
				cout << a[i][j];
				f = 1;
			}
		}
		if(f==1)cout << endl;
		f = 0;
	}




	return(0);
}