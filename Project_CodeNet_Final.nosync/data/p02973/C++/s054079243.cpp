#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

using ll=long long;
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int,int>;
using vll=vector<ll>;
using vvll=vector<vll>;


int main(void)
{
	int n;

	while(scanf("%d", &n)==1)
	{
		vi a(n), b;

		for(int i=0;i<n;i++) scanf("%d", &a[i]);

		for(int i=0;i<n;i++)
		{
			auto it=upper_bound(b.begin(), b.end(), -a[i]);

			if(it==b.end())
			{
				b.push_back(-a[i]);
			}
			else
			{
				*it=-a[i];
			}
		}
//for(int mb:b) printf("%d ", mb); printf("\n");
		printf("%u\n", b.size());
	}
	return 0;
}
