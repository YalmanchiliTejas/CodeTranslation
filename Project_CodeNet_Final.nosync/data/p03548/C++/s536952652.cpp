#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int x,y,z,ans;
int main()
{
	scanf("%d%d%d",&x,&y,&z);
	ans = floor((x-z)/(y+z));
	printf("%d\n",ans);
	return 0;
}