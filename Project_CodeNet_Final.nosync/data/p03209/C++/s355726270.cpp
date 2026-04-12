#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <utility>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <climits>
#include <numeric>
#include<stdio.h>
#include <queue>
#include <iomanip>
#include <float.h>
#include <set>
#include<functional>
#include <stack>
#include <time.h>
#include <climits>
#include <bitset>
using namespace std;
long long length[53];
long long num[53];
long long dfs(long long n, long long x) {
	if (n == 0) {
		if (x == 0)return 0;
		if (x == 1)return 1;
	}
	if (x == 0)return 0;
	if (x == 1)return 0;
	if (x > 1 && x <= 1+length[n - 1])return dfs(n - 1, x - 1);
	if (x == 1 + length[n - 1] + 1)return 1 + num[n - 1];
	if (x == length[n])return num[n];
	return num[n-1]+1+dfs(n - 1,x-2-length[n-1]);
}
signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	length[0] = 1;
	num[0] = 1;
	for (int i = 1; i <= 50; i++) {
		length[i] = length[i - 1] * 2 + 3;
		num[i] = num[i - 1] * 2 + 1;
	}
	long long n, x;
	cin >> n >> x;
	cout << dfs(n, x);
}