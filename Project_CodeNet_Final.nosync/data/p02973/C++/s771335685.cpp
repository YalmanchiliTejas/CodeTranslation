#include "bits/stdc++.h"
using namespace std;
const int N=1e5+20;
int n,a[N];
multiset <int> ms;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);

	for(int i=0;i<n;i++)
	{
		auto j=ms.lower_bound(a[i]);
		if(j!=ms.begin())
		{
			j--;
			ms.erase(j);
		}
		ms.insert(a[i]);
	}
	printf("%d",ms.size());
}