#include<bits/stdc++.h>
using namespace std;
int a[110],n,m,k;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	 {
	   scanf("%d",&m);
	   if(m>=a[k]) a[++k]=m;
	 }
	printf("%d\n",k);
	return 0;
}