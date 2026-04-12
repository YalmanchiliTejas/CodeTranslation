#include<stdio.h>
#include<algorithm>
#include<functional>
using namespace std;
int main()
{
	int X, Y, Z;
	scanf("%d%d%d", &X, &Y, &Z);
	X -= Z;
	printf("%d", X / (Y + Z));
	return 0;
}