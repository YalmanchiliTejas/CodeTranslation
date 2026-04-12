#include <cmath>
#include <queue>
#include <cstdio>
#include <algorithm>
#define rg register
#define llint long long
using namespace std;
const int N=108611;

struct ios
{
	template <typename _tp>
	inline ios operator >> (_tp &x)
	{
		x = 0;int f = 1;char c = getchar();
		for(;c<'0'||c>'9';c=getchar()) if(c=='-') f = -1;
		for(;c<='9'&&c>='0';c=getchar()) x = (x<<1)+(x<<3)+(c^48);
		x *= f;
		return *this;
	}
	template <typename _tp>
	inline ios operator << (_tp x)
	{
		char s[66];int dgt = 0;
		if(x==0) putchar('0');
		if(x<0) putchar('-'),x = -x;
		while(x) ++dgt,s[dgt] = x%10+'0',x/=10;
		while(dgt) putchar(s[dgt]),--dgt;
		return *this;
	}
	inline ios operator << (char x)
	{
		putchar(x);
		return *this;
	}
}io;

int n,cnt,inv;
int q[N];

int main()
{
	io >> n;
	for(rg int i=1;i<=n;++i)
		q[i] = -1;
	for(rg int i=1;i<=n;++i)
	{
		io >> inv;
		int l = 1,r = cnt;
		while(l<=r)
		{
			int mid = (l+r)>>1;
			if(q[mid]>=inv) l = mid+1;
			else r = mid-1;
		}
		if(q[l]==-1||q[l]>=inv) ++cnt,q[cnt] = inv;
		else q[l] = inv;
	}
	io << cnt << '\n';
	return 0;
}