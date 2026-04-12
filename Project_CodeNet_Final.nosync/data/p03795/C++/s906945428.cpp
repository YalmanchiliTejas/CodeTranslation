#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
	int n;
	int i, j;
	int x, y;
	int temp;
	scanf("%d", &n);
	x = 800 * n;
	y = n / 15 * 200;
	printf("%d\n", x - y);

}