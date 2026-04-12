#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int a,b,c;
	int sum=0;
	for(int i=0;i<3;i++)
	{
		scanf("%d",&a);
		sum=sum*10+a;
	}
	if(sum%4==0)
	printf("YES\n");
	else
	printf("NO\n");
	return 0;
}