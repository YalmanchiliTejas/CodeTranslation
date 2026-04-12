#include<bits/stdc++.h>
using namespace std;
char c[11];
int main()
{
	int i,n,k;
	char a;
	scanf("%d",&n);
	scanf("%s",c);
	scanf("%d",&k);
	a=c[k-1];
	for(i=0;i<n;i++)
	{
		if(c[i]==a)
			printf("%c",c[i]);
		else
			printf("*");
	}
	return 0;
}