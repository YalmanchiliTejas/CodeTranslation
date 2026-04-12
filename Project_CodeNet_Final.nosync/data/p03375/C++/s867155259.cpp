#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

bool chkmax(int &x,int y){return x<y?x=y,true:false;}
bool chkmin(int &x,int y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,cys;
ll d[3005][3005],fac[3005],inv[3005],pw1[3005],pw2[3005],cm[3005];

ll mod(ll x){return x>=cys?x-cys:x;}
ll C(ll x,ll y){return x<y?0:fac[x]*inv[y]%cys*inv[x-y]%cys;}

ll qpow(ll x,ll p,ll Mod){
	ll ret=1;
	for(;p;p>>=1,x=x*x%Mod) if(p&1) ret=ret*x%Mod;
	return ret;
}

int main(){
	n=readint(); cys=readint();
	fac[0]=inv[0]=pw1[0]=pw2[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%cys;
	for(int i=1;i<=n;i++) pw1[i]=pw1[i-1]*2%(cys-1);
	for(int i=1;i<=n;i++) pw2[i]=pw2[i-1]*2%cys;
	inv[n]=qpow(fac[n],cys-2,cys);
	for(int i=n-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%cys;
	d[0][0]=1;
	for(int i=0;i<=n;i++) cm[i]=C(n,i);
	for(int i=1;i<=n+1;i++) for(int j=1;j<=i;j++) d[i][j]=mod(d[i-1][j]*j%cys+d[i-1][j-1]);
	ll ans=0;
	for(int i=0;i<=n;i++){
		ll pt1=qpow(2,pw1[n-i],cys),pt2=1;
		for(int j=0;j<=i;j++){
			ll tmp=pt1*d[i+1][j+1]%cys*cm[i]%cys*pt2%cys;
			if(i&1) ans=mod(ans+cys-tmp);
			else ans=mod(ans+tmp);
			pt2=pt2*pw2[n-i]%cys;
		}
	}
	cout<<ans<<endl;
	return 0;
}