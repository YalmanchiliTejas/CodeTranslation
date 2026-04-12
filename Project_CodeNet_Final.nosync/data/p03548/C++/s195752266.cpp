#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <math.h>
#include <set>
#include <map>
#include <string>
#include <list>
#include <string.h>
#include <functional>
//#include <Windows.h>
//#include "Library.h"
//#include "Math.h"
using namespace std;
typedef long long int ll; typedef pair <double, int> P; typedef vector <int> vecint;
const int INF = 2000000000;
const double EPS = 10e-9;
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int res = 0;
	res += a / (b + c);
	a %= (b + c);
	if (a < c) res--;
	cout << res << endl;
	return 0;
}