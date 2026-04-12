#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define NINF -0x3f3f3f3f

using namespace std;

typedef pair<int,int> pii;

long long a[55];

int main (int argc, char const* argv[])
{
	int n;
	scanf("%d",&n);
	
	for (int i = 0; i < n; i += 1)
	{
		scanf("%lld",&a[i]);
	}
	
	long long ans = 0;
	while (true)
	{
		long long mx[2] = { -1, -1 };
		int pos[2] = { -1, -1 };
		for (int i = 0; i < n; i += 1)
		{
			if (a[i] > mx[0])
			{
				mx[1] = mx[0];
				pos[1] = pos[0];
				
				mx[0] = a[i];
				pos[0] = i;
			} 
			else if (a[i] > mx[1])
			{
				mx[1] = a[i];
				pos[1] = i;
			}
		}
		
		if (mx[0] < n)
			break;
		
		long long diff = mx[0]-n+1LL;
		long long x = (diff+n-1LL)/n;
	
		ans += x;
		
		for (int i = 0; i < n; i += 1)
		{
			if (i != pos[0])
			{
				a[i] += x;	
			}
			else
			{
				a[i] -= x*n;
			}
		}
	}
	
	printf("%lld\n",ans);	
	return 0;
}