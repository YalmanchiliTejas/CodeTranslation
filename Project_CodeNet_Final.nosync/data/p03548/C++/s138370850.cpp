#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;
int a, b, c;
int main()
{
	while(scanf("%d %d %d",&a, &b, &c) != EOF)
	{
		int d;
		d = (a - c)/ (b + c);
		printf("%d\n",d);
	}
}