#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;
#define min(x, y) ((x < y) ? x : y)
#define rep(x, n) for (int x = 1; x <= n; ++x)
const int inf = 214748364;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int k = a * 100 + b * 10 + c;
	if (k % 4 == 0)
		puts("YES");
	else puts("NO");
	return 0;
}
