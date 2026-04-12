#include<cstdio>
#include<cmath>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int x,y,z,n;
	scanf("%d%d%d",&x,&y,&z);
	n = (x - z)/(y + z);
	printf("%d\n",n);
}