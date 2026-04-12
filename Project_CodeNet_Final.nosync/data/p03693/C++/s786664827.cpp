#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main()
{
	int r, g, b;
	scanf("%d %d %d", &r, &g, &b);

	int sum = r * 100 + g * 10 + b;

	if (sum % 4 == 0)
		printf("YES\n");
	else
		printf("NO\n");

}