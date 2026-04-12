#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int x,y,z,ans;
	scanf("%d%d%d",&x,&y,&z);
	ans=(x-z)/(y+z);
	printf("%d",ans);
	return 0;
}