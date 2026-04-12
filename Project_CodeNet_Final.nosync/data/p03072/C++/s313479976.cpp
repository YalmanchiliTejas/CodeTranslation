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
		vi h(n);

		for(int i=0;i<n;i++) scanf("%d", &h[i]);
		int ans=0, max_h=-1;

		for(int i=0;i<n;i++)
		{
			if(max_h<=h[i])
			{
				max_h=h[i];
				ans++;
			}
		}

		printf("%d\n", ans);
	}
	return 0;
}
