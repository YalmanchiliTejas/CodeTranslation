//  Created by Sengxian on 2017/7/1.
//  Copyright (c) 2017年 Sengxian. All rights reserved.
//  
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
inline int readInt() {
	int n = 0, ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) n = n * 10 + ch - '0', ch = getchar();
	return n;
}

const int MAX_N = 200000 + 3;
int n, a[MAX_N * 2];

int main() {
	n = readInt();
	int l = MAX_N, r = MAX_N;
	for (int i = 0; i < n; ++i)
		if ((n & 1) ^ (i & 1)) a[--l] = readInt();
		else a[r++] = readInt();
	for (int i = l; i < r; ++i) printf("%d%c", a[i], i + 1 == r ? '\n' : ' ');
	return 0;
}
