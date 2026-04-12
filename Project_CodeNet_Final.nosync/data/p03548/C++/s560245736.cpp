#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int x,y,z;
	scanf("%d %d %d",&x,&y,&z);
	int ans=0;
	x=x-z;
	while(x>=y+z)
	{
		x=x-y-z;
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}