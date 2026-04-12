#include<bits/stdc++.h>
#define Rep(i,a,b) for(register int i=(a);i<=(b);++i)
using namespace std;
template<typename T>inline void read(T&x)
{
	T f;register char ch;x=0;f=1;
	for(ch=getchar();!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())x=(x*10)+(ch^48);
	x*=f;
}

const int MAXN=2e5+7;

static int n,a[MAXN],b[MAXN];

inline void init()
{
	read(n);
	Rep(i,1,n)read(a[i]),b[i]=a[i];
}

inline void solve()
{
	sort(b+1,b+n+1);
	Rep(i,1,n)if(a[i]<=b[n/2])printf("%d\n",b[n/2+1]);
	else printf("%d\n",b[n/2]);
}

int main()
{
	init();
	solve();
	return 0;
}