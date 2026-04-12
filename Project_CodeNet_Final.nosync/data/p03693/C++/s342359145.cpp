#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
#include<complex>
#include<algorithm>
#include<vector>
#include<math.h>
#include<set>
#include<map>

int main()
{
	int r, g, b;
	scanf("%d%d%d", &r, &g, &b);
	if (!((g * 10 + b) % 4)) printf("YES\n");
	else printf("NO\n");

	return 0;
}