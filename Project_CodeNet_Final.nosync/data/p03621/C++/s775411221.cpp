#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N=40010,Mo=998244353;
int s,L;
char a[N],b[N];
int A[N],B[N],rev[N],fac[N],inv[N];
inline int gi() {
    int x=0,o=1;
    char ch=getchar();
    while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
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
inline void mul(int *a,int *b,int t) {
    NTT(a,s,1);
    if(b!=a) NTT(b,s,1);
    for(int i=0;i<s;i++) a[i]=1LL*a[i]*b[i]%Mo;
    NTT(a,s,-1);
    if(b!=a) NTT(b,s,-1);
    for(int i=t+1;i<s;i++) a[i]=0;
}
int main() {
    scanf("%s%s",a,b);
    int n=strlen(a),x=0,y=0,ans=0;
    for(int i=0;i<n;i++)
	if(a[i]=='1') {
	    if(b[i]=='1') ++x;
	    else ++y;
	}
    fac[0]=1;
    for(int i=1;i<=n;i++) fac[i]=1LL*fac[i-1]*i%Mo;
    inv[n]=Pow(fac[n],Mo-2);
    for(int i=n;i;i--) inv[i-1]=1LL*inv[i]*i%Mo;
    for(s=1,L=0;s<=x+x;s<<=1) L++;
    for(int i=0;i<s;i++) rev[i]=((rev[i>>1]>>1)|(i&1)<<L-1);
    A[0]=1;
    for(int i=0;i<=x;i++) B[i]=inv[i+1];
    int t=y;
    while(t) {
	if(t&1) mul(A,B,x);
	mul(B,B,x),t>>=1;
    }
    for(int i=0;i<=x;i++) ans=(ans+A[i])%Mo;
    cout<<(1LL*ans*fac[x]%Mo*fac[y]%Mo*fac[x+y]%Mo+Mo)%Mo;
    return 0;
}