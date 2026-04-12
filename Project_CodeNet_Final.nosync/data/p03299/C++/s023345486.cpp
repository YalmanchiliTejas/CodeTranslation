#include<bits/stdc++.h>
#define llong long long
#define mkpr make_pair
#define riterator reverse_iterator
#define pll pair<llong,llong>
using namespace std;

inline int read()
{
	int x = 0,f = 1; char ch = getchar();
	for(;!isdigit(ch);ch=getchar()) {if(ch=='-') f = -1;}
	for(; isdigit(ch);ch=getchar()) {x = x*10+ch-48;}
	return x*f;
}

const int mxN = 100;
const int INF = 1e9;
const int P = 1e9+7;
int a[mxN+3];
int n;

llong quickpow(llong x,llong y)
{
	llong cur = x,ret = 1ll;
	for(int i=0; y; i++)
	{
		if(y&(1ll<<i)) {y-=(1ll<<i); ret = ret*cur%P;}
		cur = cur*cur%P;
	}
	return ret;
}

pll dfs(int l,int r,int h)
{
//	printf("l=%d r=%d h=%d\n",l,r,h);
	int h2 = INF; for(int i=l; i<=r; i++) h2 = min(h2,a[i]);
	pll ret(0ll,1ll); int mncnt = 0ll,segcnt = 0ll; llong prod1 = 1ll;
	for(int i=l,j=l; i<=r+1; i++)
	{
		if(a[i]==h2||i==r+1)
		{
			if(j<=i-1)
			{
				pll tmp = dfs(j,i-1,h2);
				ret.second = ret.second*tmp.second%P;
				prod1 = prod1*(tmp.first+tmp.second*2ll)%P;
				segcnt++;
			}
			if(i<=r)
			{
				mncnt++;
			}
			j = i+1;
		}
	}
	ret.first = (prod1*quickpow(2ll,mncnt)-ret.second*2ll%P+P)%P;
	ret.second = ret.second*quickpow(2ll,h2-h)%P;
//	printf("(%lld,%lld)\n",ret.first,ret.second);
	return ret;
}

int main()
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%lld",&a[i]);
	pll ans = dfs(1,n,0);
	printf("%lld\n",(ans.first+ans.second)%P);
	return 0;
}