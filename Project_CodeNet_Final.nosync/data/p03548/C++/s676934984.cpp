#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	double x, y, z;
	int a, b;
	while(~scanf("%lf %lf %lf", &x, &y, &z))
	{
		b = y + z;
		a = x - z;
		printf("%d\n", a/b);
	}
}