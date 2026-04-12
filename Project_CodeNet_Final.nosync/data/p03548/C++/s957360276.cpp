/* 
	Author: ankrypt
*/
#include <bits/stdc++.h>

using namespace std;

int X;
int Y;
int Z;
int finalAns;

int main()
{
	scanf("%d %d %d", &X, &Y, &Z);
	finalAns = (X - Z) / (Y + Z);
	if(finalAns < 0)
	{
		printf("0");	
	}
	else
	{
		printf("%d", finalAns);
	}
	return 0;
}
/*
	Powered by Buggy Plugin
*/
