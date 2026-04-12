#include<bits/stdc++.h>

#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long MOD=1e9+7;
const long long LINF=1e18;
const int INF=0x3f3f3f3f;
const int MAXN=200050;

ll times[MAXN],sum1[MAXN],sum2[MAXN];
ll euler(int n) {
    ll ans=n;
    for(int i=2;i*i<=n;i++) {
        if(n%i==0) {
            ans=ans/i*(i-1);
            while(n%i==0)n/=i;
        }
    }
    if(n>1)ans=ans/n*(n-1);
    return ans;
}
ll mpow(ll a,ll n,ll MOD)
{
	if(a==1||n==0)return 1;
	ll ans=1;
	a%=MOD;
	while(n!=0)
	{
		if(n&1)ans=(ans*a)%MOD;
		n>>=1;
		a=(a*a)%MOD;
	}
	return ans%MOD;
}
void solve(int T){
	ll n,x,m,ans=0,tmp,phi,pphi;
	scanf("%lld %lld %lld",&n,&x,&m);
	if(n<=m){
		tmp=x;
		for(int i=1;i<=n;i++){
			ans+=x;
			x*=x;
			x%=m;
		}
		printf("%lld",ans);
		return;
	}
	phi=euler(m);
	pphi=euler(phi);
	for(int i=0;i<pphi&&i<=n-1;i++)times[i]=1;
	ll sy=(n-1)%pphi;
	for(int i=pphi;i<=2*pphi-1&&i<=n-1;i++){
		if(i%pphi<=sy)times[i]=(n-1)/pphi;
		else times[i]=(n-1)/pphi-1;
	}
	sum1[0]=1;
	int sta=0;
	for(int i=1;i<=2*pphi-1;i++){
		sum1[i]=(sum1[i-1]*2);
		if(sum1[i]>=phi){
			sta=1;
		}
		sum1[i]%=phi;
		if(sta)sum1[i]+=phi;
	}
	for(int i=0;i<=2*pphi-1;i++){
		ans+=times[i]*(mpow(x,sum1[i],m)%m);
	}
	printf("%lld",ans);
	
}
signed main(){
	int t=1;
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//scanf("%d",&t); 
	for(int i=1;i<=t;i++){
		solve(i);
	}
}