#include<bits/stdc++.h>
using namespace std;

const int p=998244353,maxN=1<<15,g=3,ig=332748118;
int W[maxN],iW[maxN];
int fac[maxN],ifac[maxN],inv[maxN];
int qpow(int a,int k){
    int ans=1;
    while(k){
        if(k&1) ans=1LL*ans*a%p;
        a=1LL*a*a%p;
        k>>=1;
    }
    return ans;
}
 
int R[maxN];
void NTT(int d[],int n0,bool flg){
    int x=1,len=0;while(x<n0) x<<=1,len++;
    for(int i=0;i<x;i++){
        R[i]=(R[i>>1]>>1)|((i&1)<<(len-1));
        if(i<R[i]) swap(d[i],d[R[i]]);
    }
    for(int i=1,l=maxN/(i<<1);i<x;i<<=1,l>>=1)
    for(int j=0;j<x;j+=(i<<1))
    for(int k=0,u=0;k<i;k++,u+=l){
        int a0=d[j|k],a1=1LL*(flg?iW[u]:W[u])*d[j|i|k]%p;
        d[j|k]=(a0+a1)%p;d[j|i|k]=a0-a1+p;
    	if(d[j|i|k]>=p)d[j|i|k]-=p;
	}
    if(flg){
        int invx=qpow(x,p-2);
        for(int i=0;i<x;i++) d[i]=1LL*d[i]*invx%p;
    }
}

int N,M;

int F[205][maxN];
int G[maxN],H[maxN];

int C(int n,int m){
	if(n<m) return 0;
	return 1LL*fac[n]*ifac[m]%p*ifac[n-m]%p;
}

int main(){
	int w=qpow(g,(p-1)/maxN),iw=qpow(ig,(p-1)/maxN);
    W[0]=iW[0]=1;
    for(int i=1;i<maxN;i++)
        W[i]=1LL*W[i-1]*w%p,
        iW[i]=1LL*iW[i-1]*iw%p;
    inv[1]=ifac[0]=ifac[1]=fac[0]=fac[1]=1;
    for(int i=2;i<maxN;i++)
    	inv[i]=1LL*(p-p/i)*inv[p%i]%p,
    	fac[i]=1LL*fac[i-1]*i%p,
    	ifac[i]=1LL*ifac[i-1]*inv[i]%p;
    
    scanf("%d%d",&N,&M);
    F[0][0]=1;
    int n0=1;while(n0<((N+3)<<1)) n0<<=1;
    for(int j=1;j<=M;j++){
    	for(int i=0;i<n0;i++) G[i]=0;
    	for(int i=0;i<=N;i++) G[i]=1LL*F[j-1][i]*ifac[i]%p;
    	for(int i=0;i<n0;i++) H[i]=0;
    	for(int i=1;i<=N;i++) H[i]=ifac[i+2];
    	NTT(G,n0,0);NTT(H,n0,0);
    	for(int i=0;i<n0;i++) G[i]=1LL*G[i]*H[i]%p;
    	NTT(G,n0,1);
    	for(int i=0;i<=N;i++) F[j][i]=(1LL*fac[i+2]*G[i]%p+1LL*(1+i+C(i,2))%p*F[j-1][i]%p)%p;
	}
	
	int ans=0;
	for(int i=0;i<=N;i++) ans=(ans+1LL*C(N,i)*F[M][i]%p)%p;
	printf("%d\n",ans);
}