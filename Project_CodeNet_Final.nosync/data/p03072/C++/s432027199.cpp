// キョウプロ.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#pragma once

#include <stdio.h>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <sstream>
#include <vector>
#include <math.h>
#include <set>

using namespace std;

long long A, B, C, D, M, N, X, Y, Z;
long long a[10000];


int main()
{

	cin >> N;
	M = 0;
	C = 0;

	for (int i = 0; i < N; i++) {
		cin >> a[i];

		if (M <= a[i]) {
			C++;
			M = a[i];
		}
	}


	cout << C << endl;

    return 0;
}

