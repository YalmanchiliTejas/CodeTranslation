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


void max_u(ll&m, ll v)
{
	if(m<v) m=v;
}

int main(void)
{
	int n;
	while(scanf("%d", &n)==1)
	{
		vi a(n+1);

		for(int i=0;i<n;i++) scanf("%d", &a[i]);


		int m=n/2;

		vvll dp(3);

		for(auto&mdp:dp) mdp.resize(m+1);

		for(int i=0;i<m;i++)
		{
			dp[0][i+1]=dp[0][i]+a[i*2  ];
			dp[1][i+1]=dp[1][i]+a[i*2+1];
			dp[2][i+1]=dp[2][i]+a[i*2+2];
			max_u(dp[1][i+1], dp[0][i]+a[i*2+1]);
			max_u(dp[2][i+1], dp[0][i]+a[i*2+2]);
			max_u(dp[2][i+1], dp[1][i]+a[i*2+2]);
		}

		ll ans=max(dp[0][m], dp[1][m]);
		if(n&1) ans=max(ans, dp[2][m]);

		printf("%lld\n", ans);
	}
	return 0;
}
