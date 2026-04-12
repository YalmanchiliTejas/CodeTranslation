#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	int x,y,z,sum=0;
	scanf("%d %d %d",&x,&y,&z);
	for(int i = 0;i < x-y-z;i=i+y+z)
	{
		if(x-y-z-i<z)
			break;
		sum++;
	}
	printf("%d\n",sum);
	return 0;
}