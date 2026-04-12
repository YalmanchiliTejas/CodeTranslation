#include<cstdio>
#include<vector>

using namespace std;

int main(void)
{
	int n;

	while(scanf("%d", &n)==1)
	{
		vector<int> a(n), ans(n);
		for(int i=0;i<n;i++)
		{
			scanf("%d", &a[i]);
		}
		int s=0;
		int e=n-1;
		int p=n-1;
		while(p>=0)
		{
			ans[s++]=a[p--];
			if(p<0) break;
			ans[e--]=a[p--];
		}
		for(int i=0;i<n-1;i++) printf("%d ", ans[i]);
		printf("%d\n", ans[n-1]);
	}

	return 0;
}
