#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N=17000,Mo=998244353;
int fac[N],inv[N],A[N],B[N],rev[N],f[N];
inline int Pow(int x,int y) {
    int ret=1;
    while(y) {
	if(y&1) ret=1LL*ret*x%Mo;
	x=1LL*x*x%Mo,y>>=1;
    }
    return ret;
}
inline void NTT(int *a,int n,int f) {
    for(int i=0;i<n;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
    for(int i=1;i<n;i<<=1) {
	int wn=Pow(3,(Mo-1)/(i<<1)),x,y;
	for(int j=0;j<n;j+=i<<1)
	    for(int k=0,w=1;k<i;k++,w=1LL*w*wn%Mo) {
		x=a[j+k],y=1LL*a[j+k+i]*w%Mo;
		a[j+k]=(x+y)%Mo,a[j+k+i]=(x-y)%Mo;
	    }
    }
    if(f==1) return;
    reverse(a+1,a+n);
    int Inv=Pow(n,Mo-2);
    for(int i=0;i<n;i++) a[i]=1LL*a[i]*Inv%Mo;
}
inline int C(int n,int m) {
    if(n<m) return 0;
    return 1LL*fac[n]*inv[m]%Mo*inv[n-m]%Mo;
}
int main() {
    int n,m,s,L,ans=0;
    cin>>n>>m>>s>>L;
    for(s=1,L=0;s<=n+n;s<<=1) L++;
    for(int i=0;i<s;i++) rev[i]=((rev[i>>1]>>1)|((i&1)<<L-1));
    fac[0]=1;
    for(int i=1;i<=n+2;i++) fac[i]=1LL*fac[i-1]*i%Mo;
    inv[n+2]=Pow(fac[n+2],Mo-2);
    for(int i=n+2;i;i--) inv[i-1]=1LL*inv[i]*i%Mo;
    for(int i=1;i<=n;i++) B[i]=inv[i+2];
    NTT(B,s,1),f[0]=1;
    for(int i=1;i<=m;i++) {
	memset(A,0,sizeof(A));
	for(int j=0;j<=n;j++) A[j]=1LL*f[j]*inv[j]%Mo;
	NTT(A,s,1);
	for(int j=0;j<s;j++) A[j]=1LL*A[j]*B[j]%Mo;
	NTT(A,s,-1);
	for(int j=0;j<=n;j++)
	    f[j]=(1LL*A[j]*fac[j+2]+1LL*f[j]*(C(j+1,2)+1))%Mo;
    }
    for(int i=0;i<=n;i++) ans=(ans+1LL*C(n,i)*f[i])%Mo;
    cout<<(ans+Mo)%Mo;
    return 0;
}