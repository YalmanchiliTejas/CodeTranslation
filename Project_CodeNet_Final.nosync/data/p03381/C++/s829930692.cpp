# include <iostream>
# include <cstdio>
# include <algorithm>
using namespace std;
const int N = 2e5 + 12;
int n,a[N],b[N];
int main()
{
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)scanf("%d",&a[i]),b[i] = a[i];
	sort(b + 1,b + n + 1);
	for(int i = 1,j;i <= n;i++)
	{
		j = lower_bound(b + 1,b + n + 1,a[i]) - b;
		if(j > n / 2)printf("%d\n",b[n / 2]);
		else printf("%d\n",b[n / 2 + 1]);
	}
}