#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int r1,r2;
	cin >> r1 >> r2;
	printf("%Lf\n",(long double)(r1*r2)/(r1+r2));
	return 0;
}