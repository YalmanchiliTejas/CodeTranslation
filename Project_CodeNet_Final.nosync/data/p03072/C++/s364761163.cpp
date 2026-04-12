//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#define MAX_INT 2100000000
using namespace std;
typedef long long int ll;
//#include "Header.h"
int main()
{
	int n, h[30], i, ans = 0 , k = 0;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> h[i];
		k = max(k, h[i]);
		if (k <= h[i]) ans++;
	}
	cout << ans << endl;
}
