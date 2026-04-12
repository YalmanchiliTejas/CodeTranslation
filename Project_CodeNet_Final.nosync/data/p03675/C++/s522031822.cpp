#include<cstdio>
#include<algorithm>
#define MN 510000
using namespace std;

int n,a[MN],r,l=r=250000;
int main(){
	scanf("%d",&n);r--;
	for (int i=1;i<=n;i++)
	if ((i&1)^(n&1)) scanf("%d",&a[++r]);else scanf("%d",&a[--l]);
	for (int i=l;i<=r;i++) printf("%d ",a[i]);
}