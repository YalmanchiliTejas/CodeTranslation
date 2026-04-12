#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,i;
	char c[11];
	scanf("%d",&a);
	getchar();
	scanf("%s",c);
	scanf("%d",&b);
	for(i=0;i<a;i++)
	{
		if(c[i]==c[b-1])
			printf("%c",c[i]);
		else
			printf("*");
	}
	return 0;
}