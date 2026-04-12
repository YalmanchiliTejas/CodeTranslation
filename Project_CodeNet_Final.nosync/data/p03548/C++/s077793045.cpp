
#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <cstdio>
#include <string>
#include <math.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define loop(i, n) for(int i = 0; i < n; ++i)

std::vector<int> Data;




int main()
{
	int X, Y, Z;

	scanf("%d%d%d", &X, &Y, &Z);

	X -= Z;

	printf("%d\n", X / (Y + Z));
	return 0;
}