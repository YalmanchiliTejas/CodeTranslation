// ConsoleApplicationc.cpp: 定义控制台应用程序的入口点。
//
#include<iostream>
using namespace std;
long long  a, b, c, x, y;
long long one1(long long  a, long long b, long long  c, long long x, long long y)
{
	return (a*x + b * y);
}
long long two2(long long  a, long long b, long long  c, long long x, long long y)
{
	if (y > x)
	{
		return (c * 2 * x + (y - x)*b);
	}
	else
	{
		return (c * 2 * y + (x-y)*a);
	}
}
long long three3(long long  a, long long b, long long  c, long long x, long long y)
{
	if (x > y)
	{
		return (2 * c*x);
	}
	else
	{
		return (2 * c*y);
	}
}
long long  min(long long  x, long long  y)
{
	if (x < y)
		return x;
	else
		return y;
}
int main()
{
	scanf("%lld%lld%lld%lld%lld", &a, &b, &c, &x, &y);
	long long  one, two, three;
	one = two = three=0;
	one=one1(a, b, c, x, y);
	two = two2(a, b, c, x, y);
	three =three3(a, b, c, x, y);

	printf("%lld", min(one, min(two, three)));
    return 0;
}

