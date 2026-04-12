/*---Author:HenryHuang---*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=3e3+5;
typedef long long ll;
int n,p;
ll ksm(ll a,ll b,ll p){
	ll ans=1;
	while(b){
		if(b&1) ans=ans*a%p;
		b>>=1,a=a*a%p;
	}
	return ans;
}
ll C[maxn][maxn],S[maxn][maxn];
void init(){
	C[0][0]=S[0][0]=1;
	for(int i=1;i<=n+1;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j){
			S[i][j]=(S[i-1][j-1]+j*S[i-1][j])%p;
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;
		}
	}
}
ll a[32769],b[32769];
ll c[32769],d[32769];
ll p1(ll x){
	return a[x&0x00007fff]*b[x>>15]%p;
}
ll p2(ll x){
	return c[x&0x00007fff]*d[x>>15]%(p-1);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>p;init();
	a[0]=1;
	for(int i=1;i<=32768;++i){
		a[i]=a[i-1]*2%p;
	}
	b[0]=1,b[1]=a[32768];
	for(int i=2;i<=32768;++i){
		b[i]=b[i-1]*b[1]%p;
	}
	c[0]=1;
	for(int i=1;i<=32768;++i){
		c[i]=c[i-1]*2%(p-1);
	}
	d[0]=1,d[1]=c[32768];
	for(int i=2;i<=32768;++i){
		d[i]=d[i-1]*d[1]%(p-1);
	}
	ll ans=0;
	for(int i=0;i<=n;++i){
		ll tmp=p1(p2(n-i))*C[n][i]%p,owo=0;
		if(i&1) tmp=p-tmp;
		for(int j=0;j<=i;++j){
			owo=(owo+S[i+1][j+1]*p1(1ll*(n-i)*j%(p-1))%p)%p;
		}
		(ans+=tmp*owo%p)%=p;
	}
	cout<<ans<<'\n';
	return 0;
}
