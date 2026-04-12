#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int i,j,k,m,n,len;
int d[N],a[N];
bool cmp(int x,int y){return x>y;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	d[1]=a[1];
	len=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]<=d[len]) d[++len]=a[i];
		else
		{
			int p=upper_bound(d+1,d+len+1,a[i],cmp)-d;
			d[p]=a[i];
		}
	}
	printf("%d\n",len);
}