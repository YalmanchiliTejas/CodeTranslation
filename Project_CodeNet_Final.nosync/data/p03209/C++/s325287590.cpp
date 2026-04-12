#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
#include<functional>

using namespace std;

using ll=long long;
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int,int>;
using vll=vector<ll>;
using vvll=vector<vll>;


ll calc(vll&w, vll&p, int n, ll&x)
{
	ll ret=0;

	if(x<=0 || n<0) return 0;
	if(x>=w[n])
	{
		x-=w[n];
		return p[n];
	}

	x--;
	ret+=calc(w, p, n-1, x);
	if(x>0)
	{
		x--;
		ret++;
	}
	ret+=calc(w, p, n-1, x);
	x--;

	return ret;
}


int main(void)
{
	int n;
	ll x;

	while(scanf("%d%lld", &n, &x)==2)
	{
		vll p(n+1), w(n+1);

		p[0]=1;
		w[0]=1;
		for(int i=1;i<=n;i++)
		{
			w[i]=w[i-1]*2+3;
			p[i]=p[i-1]*2+1;
		}

		ll ans=0;
		ans=calc(w, p, n, x);
		printf("%lld\n", ans);
	}

	return 0;
}
