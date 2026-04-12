#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <utility>
#include <numeric>

using namespace std;
typedef long long llong;
typedef unsigned long long ullong;

const ullong MOD = 1000000000 + 7;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	cout << ((10 * b + c) % 4 ? "NO" : "YES") << endl;
}