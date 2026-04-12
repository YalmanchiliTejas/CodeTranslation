#include<bits/stdc++.h>
#define llong long long
using namespace std;

inline int read()
{
	int x = 0,f = 1; char ch = getchar();
	for(;!isdigit(ch);ch=getchar()) {if(ch=='-') f = -1;}
	for(; isdigit(ch);ch=getchar()) {x = x*10+ch-48;}
	return x*f;
}

const int N = 2e5;
const int P = 1e9+7;
char a[N+3];
llong f[N+3],sf[N+3];
int n,m; llong ans;

int main()
{
	scanf("%d%d",&n,&m); scanf("%s",a+1);
	for(int i=1; i<=m; i++) a[i] = a[i]=='R'?0:1;
	if(a[1]) {for(int i=1; i<=m; i++) a[i] ^= 1;}
	int lim = m,cur = 0;
	for(int i=1; i<=m; i++)
	{
		if(a[i]==a[1]) {cur++;}
		else
		{
			if(cur==i-1) {lim = cur&1?cur:cur+1;}
			else {if(cur&1) lim = min(lim,cur);}
			cur = 0;
		}
	}
	if(cur==m)
	{
		f[1] = 1ll; for(int i=2; i<=n; i++) f[i] = (f[i-1]+f[i-2])%P;
		ans = (f[n]+f[n-1]+f[n-1])%P;
		printf("%lld\n",ans);
	}
	else
	{
		if(n&1) {puts("0"); return 0;}
//		printf("lim=%d\n",lim);
		lim>>=1,n>>=1; f[1] = sf[1] = 1ll;
		for(int i=2; i<=n; i++)
		{
			f[i] = (sf[i-1]-sf[max(0,i-lim-2)]+P)%P; sf[i] = (sf[i-1]+f[i])%P;
		}
		for(int i=1; i<=n; i++) if(n-i<=lim)
		{
			ans = (ans+f[i]*(n-i+1ll))%P;
		}
		printf("%lld\n",(ans+ans)%P);
	}
	return 0;
}