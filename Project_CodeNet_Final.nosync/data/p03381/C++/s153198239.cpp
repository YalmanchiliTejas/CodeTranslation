//Leo
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#define N 200200
using namespace std;
int n,a[N],b[N],mid;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+1+n);
	mid=b[n/2];
	for(int i=1;i<=n;i++) if(a[i]<=mid) printf("%d\n",b[n/2+1]);else printf("%d\n",b[n/2]);
	return 0;
}