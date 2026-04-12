#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <set>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cctype>
using namespace std;
int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		int k = n / 15;
		printf("%d\n", n * 800 - 200 * k);
	}
	return 0;
}