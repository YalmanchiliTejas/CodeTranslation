#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <math.h>
#include <string.h>

using std::endl;
using std::string;

#define ll long long int
#define LEP(a, n) for(int a = 0; a < n; ++a)
#define INF 1145141919810
#define OUT std::cout
#define IN std::cin
#define itn int
#define fro for
#define sdt std

ll A, B, C, X, Y, Min;
ll Ans = 0;

int main()
{

	IN >> A >> B >> C >> X >> Y;

	if (A + B >= C * 2)
	{
		Min = std::min(X, Y);
		Ans = Min * C * 2;
		X -= Min;
		Y -= Min;
	}
	else
	{
		Ans = X * A + Y * B;
		OUT << Ans << endl;
		return 0;
	}
	
	if (X * A + Y * B >= (X + Y) * 2 * C)
	{
		Ans += (X + Y) * 2 * C;
	}
	else
	{
		Ans += X * A + Y * B;
	}

	OUT << Ans << endl;

	return 0;
}