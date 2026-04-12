#include <iostream>
using namespace std;
int a[200005],ans[200005];
int main() {
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	int in = 1;
	int m = n;
	while(1)
	{
	    ans[in++] = m;
	    m-=2;
	    if(m < 1)break;
	}
	if(n%2)m= 2;else m = 1;
	while(1)
	{
	    ans[in++] = m;
	    m+=2;
	    if(m > n)break;
	}
	for(i=1;i<=n;i++)
	printf("%d ",a[ans[i]]);
	return 0;
}
