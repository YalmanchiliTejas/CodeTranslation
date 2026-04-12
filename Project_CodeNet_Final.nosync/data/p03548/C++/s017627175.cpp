#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
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

//#include<bits/stdc++.h>


using namespace std;
int main() {
	int x, y, z;
	cin >> x >> y >> z;
	int ans = 0,d=0;
	d = x - z;
	ans = d / (y + z);

	cout << ans << endl;

	return 0;
}