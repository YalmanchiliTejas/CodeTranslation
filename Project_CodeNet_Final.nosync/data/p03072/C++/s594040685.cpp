#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
#include<queue>
#include<algorithm>
#include <functional>
#include<vector>
using namespace std;

const int N_MAX = 101;

int main() {
	int N, max_h;
	int H[N_MAX];
	int ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> H[i];
	max_h = H[0];
	ans++;

	for (int i = 1; i < N; i++) {
		if (max_h <= H[i]) {
			max_h = H[i];
			ans++;
		}
	}
	cout << ans << endl;
}