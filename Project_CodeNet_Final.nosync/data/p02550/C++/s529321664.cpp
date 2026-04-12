#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXM = 1e5 + 5;

ll f[MAXM], sum[MAXM];

int main(void)
{
	ll n;
	int x,m;
	scanf("%lld%d%d",&n,&x,&m);
	
	ll ans = 0;
	for(int i=1; i<=n; ++i)
	{
		sum[i] = sum[i-1] + x;
		
		if(f[x])
		{
			ans += (sum[i] - sum[f[x]]) * ((n-i+1) / (i-f[x]));
			
			ll rem = (n-i+1) % (i-f[x]);
			while(rem--)
			{
				ans += x;
				x = (ll)x * x %m;
			}
			break;
		}
		
		f[x] = i;
		ans += x;
		x = (ll)x * x %m;
	}
	printf("%lld",ans);
	return 0;
}