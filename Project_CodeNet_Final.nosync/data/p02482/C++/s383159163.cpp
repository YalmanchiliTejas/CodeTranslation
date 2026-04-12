#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int x,y;
	cin >> x >> y;
	printf("%d %d %.5lf",x/y,x%y,(double)x/(double)y);
}