#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <cmath>
#include <set>
#define Rep(i, x, y) for (int i = x; i <= y; i ++)
#define Dwn(i, x, y) for (int i = x; i >= y; i --)
#define RepE(i, x) for (int i = pos[x]; i; i = g[i].nex)
#define v g[i].y
using namespace std;
typedef long long ll;
typedef double db;
int a, b, c;
int main()
{
	cin >> a >> b >> c;
	puts((b * 10 + c) % 4 ? "NO" : "YES");

	return 0;
}