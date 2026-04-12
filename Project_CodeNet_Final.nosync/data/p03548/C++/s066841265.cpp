#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

int main()
{
	int x, y, z, ans;
	scanf("%d %d %d", &x, &y, &z);
	ans = (x - z)/(y + z);
	printf("%d\n", ans);
	return 0;
}