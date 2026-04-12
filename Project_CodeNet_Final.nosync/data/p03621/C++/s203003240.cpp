#define _USE_MATH_DEFINES_
#include <bits/stdc++.h>

#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;
typedef long long ll;
typedef vector<ll> vec;

string A,B;
const ll MOD=998244353,MAX_A_LEN=1e4,MAX_M2=1<<14;
ll fact[MAX_A_LEN+2],omg[MAX_M2<<1];

ll mpw(ll n,ll m){
	ll ret=1;
	while(m>0){
		if (m&1){
			ret*=n;
			ret%=MOD;
		}
		n*=n;
		n%=MOD;
		m>>=1;
	}
	return ret;
}
ll minv(ll n){
	return mpw(n,MOD-2);
}
ll M,E,m2;

vec fft(const vec &p,ll n,ll u=0,ll s=1){
	vec ret(n);
	if (n==1){
		ret[0]=p[u];
	}else{
		vec a=fft(p,n>>1,u,s<<1),b=fft(p,n>>1,u+s,s<<1);
		ll c=(MAX_M2<<1)/n;
		REP(i,n>>1){
			ll w1=omg[i*c],w2=omg[i*c+MAX_M2];
			ret[i]=(a[i]+w1*b[i]%MOD)%MOD;
			ret[i+(n>>1)]=(a[i]+w2*b[i]%MOD)%MOD;
		}
	}
	return ret;
}

vec ifft(const vec &p,ll n,ll u=0,ll s=1){
	vec ret(n);
	if (n==1){
		ret[0]=p[u];
	}else{
		vec a=ifft(p,n>>1,u,s<<1),b=ifft(p,n>>1,u+s,s<<1);
		ll c=(MAX_M2<<1)/n;
		REP(i,n>>1){
			ll w1=omg[((MAX_M2<<1)-i*c)%(MAX_M2<<1)],w2=omg[MAX_M2-i*c];
			ret[i]=(a[i]+w1*b[i]%MOD)%MOD;
			ret[i+(n>>1)]=(a[i]+w2*b[i]%MOD)%MOD;
		}
	}
	if (u==0 && s==1){
		REP(i,n){
			ret[i]*=minv(n);
			ret[i]%=MOD;
		}
	}
	return ret;
}

vec mul(vec p, vec q){
	p.resize(m2<<1);
	q.resize(m2<<1);
	vec u=fft(p,m2<<1),v=fft(q,m2<<1),w(m2<<1);
	REP(i,m2<<1){
		w[i]=u[i]*v[i]%MOD;
	}
	vec ret=ifft(w,m2<<1);
	ret.resize(m2);
	return ret;
}

vec ppw(vec p,ll m){
	vec ret(m2);
	ret[0]=1;
	while(m>0){
		if (m&1){
			ret=mul(ret,p);
		}
		p=mul(p,p);
		m>>=1;
	}
	return ret;
}
		
int main(){
	cin>>A>>B;
	REP(i,(ll)A.size()){
		if (A[i]=='1' && B[i]=='1'){
			M++;
		}else if (A[i]=='1' && B[i]=='0'){
			E++;
		}
	}
	omg[0]=1;
	REP(i,(MAX_M2<<1)-1){
		omg[i+1]=omg[i]*968855178%MOD;
	}
	m2=1;
	while(m2<=M){
		m2<<=1;
	}
	fact[0]=1;
	REP(i,(ll)A.size()+1){
		fact[i+1]=fact[i]*(i+1)%MOD;
	}
	vec p(m2);
	REP(i,M+1){
		p[i]=minv(fact[i+1]);
	}
	vec q=ppw(p,E);
	ll ans=0;
	REP(i,M+1){
		ans+=q[i];
		ans%=MOD;
	}
	ans=(ans*fact[E]%MOD*fact[M]%MOD*fact[E+M]%MOD);
	cout<<ans<<endl;
	return 0;
}