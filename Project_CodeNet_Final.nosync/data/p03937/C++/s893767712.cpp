#include<bits/stdc++.h>
using namespace std;
char p[105];
main()
{
	int a,b,c=0;
	scanf("%d%d",&a,&b);
	for(int i = 0;i < a;i++)
	{
		scanf("%s",p);
		for(int j = 0;j < b;j++)
		{
			if(p[j]=='#')
			c++;
		}
	}
	if(c==a+b-1)
	printf("Possible");
	else
	printf("Impossible");
}
