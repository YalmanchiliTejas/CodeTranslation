#include<iostream>
#include<cstdio>
#include<algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FOF(i,a,b) for(int i=a;i< b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=100100,P=998244353;
int n,m,L,o,ans;
int fc[N],vf[N],iv[N],rv[N],W[N],a[N],b[N],f[N];
int qpw(int x,int y){int z=1;for(;y;y>>=1,x=1ll*x*x%P)if(y&1) z=1ll*z*x%P;return z;}
int C(int x,int y){return 1ll*fc[x]*vf[x-y]%P*vf[y]%P;}
void ini(int n){
	for(L=1,o=0;L<=n;L<<=1,o++);
	FOF(i,1,L) rv[i]=rv[i>>1]>>1|(i&1)<<(o-1);
	iv[1]=fc[0]=vf[0]=1;
	FOR(i,2,L) iv[i]=1ll*iv[P%i]*(P-P/i)%P;
	FOR(i,1,L) fc[i]=1ll*fc[i-1]*i%P,vf[i]=1ll*vf[i-1]*iv[i]%P;
	int W1=qpw(3,(P-1)>>o);W[L>>1]=1;
	FOF(i,(L>>1)+1,L) W[i]=1ll*W[i-1]*W1%P;
	ROF(i,(L>>1)-1,0) W[i]=W[i<<1];
}
void DFT(int *A,int L){
	static unsigned long long B[N];
	FOF(i,0,L) B[i]=A[rv[i]];
	for(int i=1,t;i<L;i<<=1)for(int j=0,s=i<<1;j<L;j+=s)FOF(k,0,i)
		t=B[i+j+k]*W[i+k]%P,B[i+j+k]=B[j+k]+P-t,B[j+k]+=t;
	FOF(i,0,L) A[i]=B[i]%P;
}
void IFT(int *A,int L){
	reverse(A+1,A+L);DFT(A,L);
	int nv=P-(P-1)/L;
	FOF(i,0,L) A[i]=1ll*A[i]*nv%P;
}
void work(){
	FOF(i,0,L) a[i]=i<=n?1ll*f[i]*vf[i]%P:0;
	FOF(i,0,L) b[i]=i<=n?vf[i+2]:0;
	DFT(a,L);DFT(b,L);
	FOF(i,0,L) a[i]=1ll*a[i]*b[i]%P;IFT(a,L);
	FOR(i,0,n) f[i]=(1ll*fc[i+2]*a[i]%P-1ll*i*f[i]%P+P)%P;
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d%d",&n,&m);
	ini(n<<1);f[0]=1;
	FOR(i,1,m) work();
	FOR(i,0,n) (ans+=1ll*C(n,i)*f[i]%P)%=P;
	cout<<ans<<'\n';
}