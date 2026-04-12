#include<bits/stdc++.h>
using namespace std;

const int MAXN=4005;
typedef long long ll;
ll n,MOD,C[MAXN][MAXN],f[MAXN][MAXN],p[MAXN];

ll qpow(ll a,ll b){
	ll ans=1,base=a;
	while(b){
		if(b&1)(ans*=base)%=MOD;
		(base*=base)%=MOD;
		b>>=1;
	}
	return ans;
}

ll qpowt(ll a,ll b){
	ll ans=1,base=a;
	while(b){
		if(b&1)(ans*=base)%=(MOD-1);
		(base*=base)%=(MOD-1);
		b>>=1;
	}
	return ans;
}


void get(){
	for(ll i=0;i<=n;i++)C[i][0]=1;
	for(ll i=1;i<=n;i++){
		    //c[i][0]=1;  
       // c[i][i]=1;  
		for(ll j=1;j<=i;j++){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
		}
	}
	for(ll i=0;i<=n;i++){
		f[i][0]=1;
		for(ll j=1;j<=i;j++){
			f[i][j]=f[i-1][j-1]+((f[i-1][j]*(j+1))%MOD);
			f[i][j]%=MOD;
		}
	}
	for(ll i=0;i<=n;i++){
		ll B=qpow(2,1ll*(n-i));
		ll mul=1;
		for(ll j=0;j<=i;j++){
			p[i]+=f[i][j]*mul;	
			p[i]%=MOD;
			mul*=B;mul%=MOD;
		}
		p[i]*=qpow(2,qpowt(2,n-i));
		p[i]%=MOD;
	}
}

//ans=sigma (-1)^i * C(n,i)*f[i];

inline void add(ll &a,ll b){
	a+=b;if(a>=b)a-=b;
}

int main(){
	scanf("%lld%lld",&n,&MOD);
	get();
	ll ans=0;
	for(ll i=0;i<=n;i++){
		ans+=((qpow(-1,i)*C[n][i])%MOD)*p[i];
		ans%=MOD;add(ans,MOD);
	} 
	cout<<ans<<endl;
	return 0;
}