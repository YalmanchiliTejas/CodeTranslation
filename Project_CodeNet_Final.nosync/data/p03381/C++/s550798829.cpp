#include<cstdio>
#include<vector>
#include<algorithm>


using namespace std;
using vi=vector<int>;

const int NUM_MAX=200000;

int main(void)
{
	int n;

	while(scanf("%d", &n)==1)
	{
		vi a(n), x(n);

		for(int i=0;i<n;i++)
		{
			scanf("%d", &a[i]);
			x[i]=a[i];
		}
		sort(x.begin(), x.end());

		int h=(n-1)/2;
		for(int i=0;i<n;i++)
		{
			if(a[i]<=x[h]) printf("%d\n", x[h+1]);
			else printf("%d\n", x[h]);
		}
	}

	return 0;
}
