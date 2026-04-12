#include<bits/stdc++.h>
#define llong long long
#define mkpr make_pair
#define x first
#define y second
#define iter iterator
#define riter reversed_iterator
#define y1 Lorem_ipsum_
#define tm dolor_sit_amet_
using namespace std;

inline int read()
{
	int x = 0,f = 1; char ch = getchar();
	for(;!isdigit(ch);ch=getchar()) {if(ch=='-') f = -1;}
	for(; isdigit(ch);ch=getchar()) {x = x*10+ch-48;}
	return x*f;
}

const int mxN = 1e7;
const int P = 998244353;
llong fact[mxN+3],facti[mxN+3];
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
void initfact(int n)
{
	fact[0] = 1ll; for(int i=1; i<=n; i++) {fact[i] = fact[i-1]*i%P;}
	facti[n] = quickpow(fact[n],P-2); for(int i=n-1; i>=0; i--) {facti[i] = facti[i+1]*(i+1ll)%P;}
}
llong comb(llong x,llong y) {return x<0||y<0||x<y?0ll:fact[x]*facti[y]%P*facti[x-y]%P;}

int main()
{
	initfact(mxN);
	n = read();
	llong ans = quickpow(3ll,n);
	for(int i=n/2+1; i<=n; i++)
	{
		llong tmp = comb(n,i)%P*quickpow(2ll,n-i+1)%P;
		ans = (ans-tmp+P)%P;
	}
	printf("%lld\n",ans);
	return 0;
}