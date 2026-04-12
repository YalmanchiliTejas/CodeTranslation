#include<iostream>
#include<algorithm>
#include<cstring>
#include<fstream>
#include<set>
#include<queue>
#include<map>
#include<vector>
using namespace std;
#define N 200005
int n,a[N],b[N],l,r;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b,b+n);
	l=b[n/2-1];
	r=b[n/2];
	for(int i=0;i<n;i++)
	{
		if(a[i]<=l)printf("%d\n",r);
		else printf("%d\n",l);
	}
	return 0;
}