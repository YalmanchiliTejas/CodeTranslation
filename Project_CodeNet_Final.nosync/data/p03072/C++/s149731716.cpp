#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <list>
#include <set>
#include <ctime>
using namespace std;
typedef long long ll;

const int INF = 100000000;



int main(int argc, char *args[]) {
	int N; cin >> N;
	int H[21];
	int counter = 0;
	for (int i = 0; i < N; i++) {
		cin >> H[i];
	}
	for (int i = 0; i < N; i++) {
		bool flag = true;
		for (int j = 0; j < i; j++) {
			if (H[j] > H[i]) {
				flag = false;
				break;
			}
		}
		if (flag == true)counter++;
	}
	cout << counter << endl;

}