#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	int l=0,r=n-1;
	for(int i=n-1;i>=0;i--)if((n-1-i)&1)b[r--]=a[i];else b[l++]=a[i];
	for(int i=0;i<n;i++)printf("%d ",b[i]);
	return 0;
}