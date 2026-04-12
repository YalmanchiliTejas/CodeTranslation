#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<iostream>
#include<iostream>
#include<cctype>
#include<cstdio>
#include<vector>
#include<stack>
#include<queue>
#include <algorithm>
#include<math.h>
#include<set>
#include<map>
#include <sstream>
#include<iomanip>
#include <ctype.h>
using namespace std;

//#include<bits/stdc++.h>

int main() {
	
	long long int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	long long int r = 0;
	r = x * 2 * c;
	if (y > x)r += (y - x)*b;

	long long int t = 0;
	t = y * 2 * c;
	if (x > y)t += (x - y)*a;

	t = min(t, a*x + b*y);
	cout << min(r, t) << endl;

	

	return 0;
}