#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
#include <iomanip>
#include<queue>
#include<algorithm>
#include <functional>
#include<vector>
using namespace std;

int N, K;
string S;

int main() {
	cin >> N;
	cin >> S;
	cin >> K;
	for (int i = 0; i < N; i++) {
		if (S[i] != S[K - 1]) {
			S[i] = '*';
		}
	}

	cout << S << endl;
}