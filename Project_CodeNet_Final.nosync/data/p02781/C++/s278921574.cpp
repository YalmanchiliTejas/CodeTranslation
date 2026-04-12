#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>

using namespace std;

using ll=long long;
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int,int>;
using vll=vector<ll>;
using vvll=vector<vll>;
using vpii=vector<pii>;

#define PI 3.1415926535897932384626433832795


ll nCr(int n, int r)
{
	ll ret=1;

	if(r*2>n) r=n-r;

	for(int i=0;i<r;i++)
	{
		ret=ret*(n-i)/(i+1);
	}
	return ret;
}


int calc_u(int k)
{
	int u=1;
	for(int i=0;i<k;i++) u*=9;
	return u;
}


int main(void)
{
	char n[101+2];
	int k;
	while(scanf("%101[0-9]\n%d\n", n, &k)==2)
	{
		int l=strlen(n);
		vi a(l);

		for(int i=0;i<l;i++) a[i]=n[i]-'0';

		int ans=0;
		for(int i=0;i<l;i++)
		{
			int r=l-i;

			if(r<k) break;
			if(r>k && a[i]>0) ans+=nCr(r-1, k)*calc_u(k);
			for(int j=1;j<a[i];j++)
			{
				ans+=nCr(r-1, k-1)*calc_u(k-1);
			}
			if(a[i]>0)
			{
				k--;
				if(k<=0)
				{
					ans++;
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
