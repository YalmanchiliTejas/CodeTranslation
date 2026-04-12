#include<bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;
int b[N];
struct node
{
	int k,sum;	
}a[N];
int cmp(node x,node y)
{
	return x.sum<y.sum;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].sum);
		a[i].k=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n/2;i++)
		b[a[i].k]=a[n/2+1].sum;
	for(int i=n/2+1;i<=n;i++)
		b[a[i].k]=a[n/2].sum;
	for(int i=1;i<=n;i++)
		cout<<b[i]<<endl;
}