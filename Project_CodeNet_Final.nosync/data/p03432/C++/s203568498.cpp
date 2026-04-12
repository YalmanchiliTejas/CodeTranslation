#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=(a),_ed=(b);i<=_ed;++i)
#define DREP(i,a,b) for(int i=(a),_ed=(b);i>=_ed;--i)
#define mp(x,y) make_pair((x),(y))
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
inline int read(){
    register int x=0,f=1;register char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=0;ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch^'0');ch=getchar();}
    return f?x:-x;
}

const int mod=998244353;
int n,m,fac[8005],ifc[8005],f[8005],g[17000],A[17000];
inline void inc(int& x,int y){x=x+y<mod?x+y:x+y-mod;}
inline int power(int b,int n){int ans=1;for(;n;n>>=1,b=1ll*b*b%mod)if(n&1)ans=1ll*ans*b%mod;return ans;}
inline int C(int n,int m){return (n<0||m<0||n<m)?0:1ll*fac[n]*ifc[m]%mod*ifc[n-m]%mod;}

int trans[17000],w[17000];
void NTT(int* a,int n){
	static ull f[17000];
	REP(i,0,n-1)f[i]=a[i];
	REP(i,0,n-1)if(i<trans[i])swap(f[i],f[trans[i]]);
	for(int len=2,d=1;len<=n;d=len,len<<=1)
		for(int p=0;p<n;p+=len)
			for(int i=p;i<p+d;++i){
				int t=f[i+d]*w[d+i-p]%mod;
				f[i+d]=f[i]+mod-t,f[i]+=t;
			}
	REP(i,0,n-1)a[i]=f[i]%mod;
}
void times(int* f,int* a,int m1,int m2,int lim){
	static int g[17000];
	int n=1;for(;n<m1+m2-1;n<<=1);
	REP(i,0,n-1)trans[i]=(trans[i>>1]>>1)|(i&1?(n>>1):0);
	for(int len=2,d=1;len<=n;d=len,len<<=1){
		int e=power(3,(mod-1)/len);
		REP(i,w[d]=1,d-1)w[d+i]=1ll*w[d+i-1]*e%mod;
	}
	REP(i,m1,n-1)f[i]=0;REP(i,0,m2-1)g[i]=a[i];REP(i,m2,n-1)g[i]=0;
	NTT(f,n),NTT(g,n);
	REP(i,0,n-1)f[i]=1ll*f[i]*g[i]%mod;
	NTT(f,n);int inv=power(n,mod-2);
	reverse(f+1,f+n);
	REP(i,0,lim-1)f[i]=1ll*f[i]*inv%mod;
	REP(i,lim,n-1)f[i]=0;
}

int main(){
	// freopen("matrix.in","r",stdin);
	// freopen("matrix.out","w",stdout);
	REP(i,fac[0]=1,8004)fac[i]=1ll*fac[i-1]*i%mod;
	ifc[8004]=power(fac[8004],mod-2);
	DREP(i,8004,1)ifc[i-1]=1ll*ifc[i]*i%mod;
	n=read(),m=read();
	REP(i,0,n)f[i]=1;
	REP(i,3,n)A[i]=ifc[i];
	REP(t,1,m){
		memcpy(g,f,sizeof f);
		memset(f,0,sizeof f);
		REP(i,0,n){
			inc(f[i],1ll*C(i,0)*g[i]%mod);
			inc(f[i],1ll*C(i,1)*g[i]%mod);
			inc(f[i],1ll*C(i,2)*g[i]%mod);
		}
		g[0]=g[1]=0;
		REP(i,2,n)g[i]=1ll*g[i]*ifc[i-2]%mod;
		times(g,A,n+1,n+1,n+3);
		REP(i,0,n)inc(f[i],1ll*g[i+2]*fac[i]%mod);
	}
	printf("%d\n",f[n]);
	return 0;
}
