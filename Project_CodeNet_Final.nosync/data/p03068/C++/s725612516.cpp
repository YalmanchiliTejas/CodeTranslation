#include <bits/stdc++.h>
using namespace std;
char a[11];
int main()
{
	int n,m,i;
	scanf("%d",&n);
	scanf("%s",a);
	scanf("%d",&m);
	for(i=0;i<n;i++)
	{
		if(a[i]!=a[m-1])
			printf("*");
		else
			printf("%c",a[i]);
	}
    return 0;
}