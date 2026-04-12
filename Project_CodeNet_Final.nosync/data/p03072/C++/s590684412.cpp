
//#include"pch.h"
//#define _CRT_SECURE_NO_WARNINGS


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
	int N;
	int H, M=0;
	int ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> H;
		if (M <= H) {
			M = H;
			ans++;
		}
	}
	cout << ans << endl;




	return(0);
}