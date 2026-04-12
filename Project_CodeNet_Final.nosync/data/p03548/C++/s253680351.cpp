#include<cstdio>
#include<cmath>
#include<queue>
#include<algorithm>
#include<cstring>
int main()
{
	int x,y,z;
	int i,n,j;
	scanf("%d%d%d",&x,&y,&z);
i=2*z;
j=i+y;
n=(x-j)/(z+y);
printf("%d\n",n+1);
}