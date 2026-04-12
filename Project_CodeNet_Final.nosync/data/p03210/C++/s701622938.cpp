#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	int x;
	cin >> x;
	if (x == 7 || x == 5 || x == 3)
		printf("YES");
	else
		printf("NO");
}