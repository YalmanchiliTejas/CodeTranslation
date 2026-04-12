#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAX_N 200005

using namespace std;

int n;
int a[MAX_N];
int t[MAX_N];

void read()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),t[i]=a[i];
}

void work()
{
	int l,r;
	nth_element(t+1,t+(n>>1),t+1+n),l=t[(n>>1)];
	nth_element(t+1,t+(n>>1)+1,t+1+n),r=t[(n>>1)+1];
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=l) printf("%d\n",r);
		else printf("%d\n",l);
	}
}

int main()
{
	read();
	work();
}
