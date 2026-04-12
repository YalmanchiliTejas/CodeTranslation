#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

int n;

int main()
{
	scanf("%d", &n);
	printf("%d\n", n * 800 - (n / 15) * 200);
}