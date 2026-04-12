#pragma GCC optimize(2)
#pragma G++ optimize(2)
#include<bits/stdc++.h>
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define sd(a) scanf("%lf",&a)
#define ss(a) scanf("%s",a)
#define ms(a) memset(a,0,sizeof(a))
#define repi(i,a,b) for(register int i=a;i<=b;++i)
#define repd(i,a,b) for(register int i=a;i>=b;--i)
#define reps(s) for(int i=head[s],v=e[i].to;i;i=e[i].nxt,v=e[i].to)
#define ce(i,r) i==r?'\n':' '
#define pb push_back 
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define pr(x) cout<<#x<<": "<<x<<endl
using namespace std;
typedef long long ll;
const int MAX_N=2e5+5;
const int mod=1e9+7;
int a[MAX_N],sum[MAX_N];
int main()
{
	int n; si(n);
	repi(i,1,n) si(a[i]);
	sum[n+1]=0;
	repd(i,n,1) sum[i]=(1ll*a[i]+sum[i+1])%mod;
	int ans=0;
	repi(i,1,n-1) ans=(ans+1ll*a[i]*sum[i+1]%mod)%mod;
	printf("%d\n",ans);
	return 0;
}