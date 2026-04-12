#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int n;
int a[200005];
int ans[200005];

void work1()
{
	int time=0,add=2;
	ans[n/2+1]=1;
	int p=n/2,q=n/2+2;
	
	while (time<=n/2)
	{
		ans[p--]=add++;
		ans[q++]=add++;
		time++;
	}
	
	ans[p]=add;
}

void work2()
{
	int time=0,add=2;
	ans[n/2+1]=1;
	int p=n/2,q=n/2+2;
	
	while (time<=n/2)
	{
		ans[q++]=add++;
		ans[p--]=add++;
		time++;
	}
}

int main()
{
	
	scanf ("%d",&n);
	for (int i=1;i<=n;i++) scanf ("%d",&a[i]);
	
	if (n%2==0) work1();
	else work2();
	
	//for (int i=1;i<=n;i++)
		//cout<<ans[i]<<' ';
	//cout<<endl;
	
	for (int i=1;i<=n;i++) printf("%d ",a[ans[i]]);
}