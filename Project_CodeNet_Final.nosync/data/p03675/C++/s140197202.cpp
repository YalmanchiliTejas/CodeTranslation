#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,a[200100],dl[400100],head,tail;
	head=100010;
	tail=head-1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);	
		if(i&1) dl[++tail]=a[i];
		else dl[--head]=a[i];
	}
	if(n&1) for(int i=tail;i>=head;i--) printf("%d ",dl[i]);
	else for(int i=head;i<=tail;i++) printf("%d ",dl[i]);
	return 0;
} 