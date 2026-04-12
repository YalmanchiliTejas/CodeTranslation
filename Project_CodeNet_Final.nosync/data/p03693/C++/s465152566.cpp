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

	int a, b, c;
	cin >> a >> b >> c;
	a *= 100;
	b *= 10;
	c += a + b;
	if (c % 4)cout << "NO" << endl;
	else cout << "YES" << endl;
	return 0;

}


