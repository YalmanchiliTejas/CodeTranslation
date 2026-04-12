#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+9;
const double ep=1e-7;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
const double pi=acos(-1);
#define debug1 puts("?");
#define debug(x) cout<<"##"<<(x)<<endl;
#define mk make_pair
#define PII pair<int,int>
#define PIII pair<PII,int>
#define PIL pair<int,ll>
#define PLL pair<ll,ll>
#define eb emplace_back
#define fi first
#define se second
#define rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define sd(x) scanf("%d",&(x))
#define slld(x) scanf("%lld",&(x))
#define sdd(x,y) scanf("%d%d",&(x),&(y))
#define sc(s) scanf("%s",(s))
#define pd(x) printf("%d\n",(x))
#define plld(x) printf("%lld\n",(x))
#define pdk(x) printf("%d ",(x))
typedef long long ll;
ll n,a[maxn],sum[maxn],res;
void solve()
{
	slld(n);
	rep(i,1,n)slld(a[i]);
	for(int i=n;i>=1;i--)sum[i]=(sum[i+1]+a[i])%mod;
	rep(i,1,n-1)res=(res+a[i]*sum[i+1]%mod)%mod;
	plld(res);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T=1;
//	sd(T);
	while(T--)solve();
} 