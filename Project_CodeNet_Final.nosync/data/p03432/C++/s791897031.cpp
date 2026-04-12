#include<bits/stdc++.h>
using namespace std;
const int N=32010;
const int mod=998244353;
int gi() {
    int x=0,o=1;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
struct poly {
    vector<int> v;
    int &operator[](int x) {
        return v[x];
    }
    void set(int n) {
        v.resize(n+1);
    }
    int get() {
        return (int)v.size()-1;
    }
};
int qpow(int a,int b) {
    int ret=1;
    while(b) {
        if(b&1) ret=1ll*ret*a%mod;
        a=1ll*a*a%mod,b>>=1;
    }
    return ret;
}
int add(int a,int b) {
    return a+b>=mod?a+b-mod:a+b;
}
int sub(int a,int b) {
    return a-b<0?a-b+mod:a-b;
}
void inc(int &a,int b) {
    a=(a+b>=mod)?a+b-mod:a+b;
}
void dec(int &a,int b) {
    a=(a-b<0)?a-b+mod:a-b;
}
void NTT(poly &a,int n,int f,vector<int> &r) {
    for(int i=0;i<n;i++)
        if(i<r[i]) swap(a[i],a[r[i]]);
    for(int i=1;i<n;i<<=1) {
        int wn=qpow(3,(mod-1)/(i<<1));
        if(f==-1) wn=qpow(wn,mod-2);
        for(int p=i<<1,j=0;j<n;j+=p) {
            int w=1;
            for(int k=0;k<i;k++,w=1ll*w*wn%mod) {
                int x=a[j+k],y=1ll*w*a[j+k+i]%mod;
                a[j+k]=add(x,y),a[j+k+i]=sub(x,y);
            }
        }
    }
    if(f==-1) {
        int inv=qpow(n,mod-2);
        for(int i=0;i<n;i++) a[i]=1ll*a[i]*inv%mod;
    }
}
poly operator*(poly a,poly b) {
    int n=a.get(),m=b.get(),l=0;
    m+=n;for(n=1;n<=m;n<<=1) ++l;
    vector<int> r(n);
    for(int i=0;i<n;i++) r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
    a.set(n-1),b.set(n-1);
    NTT(a,n,1,r),NTT(b,n,1,r);
    for(int i=0;i<n;i++) a[i]=1ll*a[i]*b[i]%mod;
    NTT(a,n,-1,r);
    a.set(m);return a;
}
int n,m,fac[N],ifac[N];
poly f[N];
void init() {
    const int n=30000;
    fac[0]=1;for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
    ifac[n]=qpow(fac[n],mod-2);
    for(int i=n-1;i>=0;i--) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
}
int C(int n,int m) {
    if(n<0||m<0||n<m) return 0;
    return 1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int main() {
    n=gi(),m=gi(),init();
    f[0].set(n),f[0][0]=1;
    for(int i=0;i<m;i++) {
        f[i+1].set(n);
        for(int j=0;j<=n;j++) inc(f[i+1][j],1ll*f[i][j]*add(C(j+1,2),1)%mod);
        poly A,B;A.set(n),B.set(n+2);
        for(int j=0;j<=n;j++) A[j]=1ll*f[i][j]*ifac[j]%mod;
        for(int j=3;j<=n+2;j++) B[j]=ifac[j];
        poly C=A*B;
        for(int j=0;j<=n;j++) inc(f[i+1][j],1ll*C[j+2]*fac[j+2]%mod);
    }
    int ans=0;
    for(int i=0;i<=n;i++) {
        inc(ans,1ll*C(n,i)*f[m][i]%mod);
    }
    printf("%d\n",ans);
    return 0;
}
