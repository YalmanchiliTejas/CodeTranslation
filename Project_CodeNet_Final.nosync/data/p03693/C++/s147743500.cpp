#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <iostream>

#pragma warning(disable:4996)

using namespace std;


int main()
{
	int r, g, b;
	while (cin >> r >> g >> b)
	{
		bool res = (r * 100 + g * 10 + b) % 4 == 0 ? 1 : 0;
		cout << (res ? "YES" : "NO") << endl;
	}
	return 0;
}
