#include<bits/stdc++.h>
using namespace std;
const long long md=998244353;
const int maxn=200100;
long long fac[maxn],inv[maxn];
long long powd(long long x,long long y){
	long long res=1;
	while(y){
		if(y&1) res=res*x%md;
		x=x*x%md;
		y>>=1;
	}
	return res;
}
long long C(int x,int y){
	if(x<0||y<0||x<y) return 0;
	return fac[x]*inv[y]%md*inv[x-y]%md;
}
long long f[maxn],g[maxn],h[maxn];
int rev[maxn];
long long wn[100],rwn[100];
int csh(int n){
	int l=1,ws=0;
	while(l<n) l<<=1,ws++;
	n=l;
	for(int i=0;i<n;i++)
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(ws-1));
	for(int i=1;i<=ws;i++){
		wn[i]=powd(3,(md-1)>>i);
		rwn[i]=powd(wn[i],md-2);
	}
	return n;
}
void NTT(long long *a,int n,int op){
	for(int i=0;i<n;i++)
		if(i<rev[i])
			swap(a[i],a[rev[i]]);
	long long w,t1,t2;
	int id=0;
	for(int l=2;l<=n;l<<=1){
		id++;
		for(int i=0;i<n;i+=l){
			w=1;
			for(int j=i;j<i+(l>>1);j++){
				t1=a[j],t2=a[j+(l>>1)]*w%md;
				a[j]=(t1+t2)%md;
				a[j+(l>>1)]=(t1-t2+md)%md;
				w=w*(op==1?wn[id]:rwn[id])%md;
			}
		}
	}
	if(op==-1){
		w=powd(n,md-2);
		for(int i=0;i<n;i++)
			a[i]=a[i]*w%md;
	}
}
void Mult(long long *a,long long *b,int n,long long *c){
	static long long dA[maxn],dB[maxn];
	n=csh(n);
	for(int i=0;i<n;i++)
		dA[i]=a[i],dB[i]=b[i];
	NTT(dA,n,1);
	NTT(dB,n,1);
	for(int i=0;i<n;i++)
		c[i]=dA[i]*dB[i]%md;
	NTT(c,n,-1);
}
int main(){
//	freopen("F.in","r",stdin);
//	freopen("F.out","w",stdout);

	int n,m;
	scanf("%d%d",&n,&m);
	fac[0]=1;
	for(int i=1;i<maxn;i++)
		fac[i]=fac[i-1]*i%md;
	inv[maxn-1]=powd(fac[maxn-1],md-2);
	for(int i=maxn-1;i>=1;i--)
		inv[i-1]=inv[i]*i%md;

	f[0]=1;
	for(int i=1;i<=n;i++)
		g[i]=inv[i+2];
	for(int i=1;i<=m;i++){
		for(int j=0;j<=n*2+2;j++)
			h[j]=0;
		Mult(f,g,n*2+2,h);
		for(int j=0;j<=n;j++)
			h[j]=(h[j]*fac[j+2]+f[j]*(C(j+1,2)+1)%md*fac[j]%md)%md;
		for(int j=0;j<=n;j++)
			f[j]=h[j]*inv[j]%md;
	}
	long long ans=0;
	for(int i=0;i<=n;i++)
		ans=(ans+h[i]*C(n,i))%md;
	printf("%lld\n",ans);
	return 0;
}
