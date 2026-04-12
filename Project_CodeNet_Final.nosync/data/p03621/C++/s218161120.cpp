#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
const int mod=998244353;
int gi() {
    int x=0,o=1;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
int qpow(int a,int b) {
    int ret=1;
    while(b) {
        if(b&1) ret=1ll*ret*a%mod;
        a=1ll*a*a%mod,b>>=1;
    }
    return ret;
}
struct poly {
    vector<int> v;
    int& operator[](int x) {
        return v[x];
    }
    void set(int n) {
        v.resize(n+1);
    }
    int get() {
        return (int)v.size()-1;
    }
};
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
                a[j+k]=(x+y)%mod,a[j+k+i]=(x-y+mod)%mod;
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
    m+=n;for(n=1;n<=m;n<<=1) l++;
    vector<int> r(n);
    for(int i=0;i<n;i++) r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
    a.set(n-1),b.set(n-1);
    NTT(a,n,1,r),NTT(b,n,1,r);
    for(int i=0;i<n;i++) a[i]=1ll*a[i]*b[i]%mod;
    NTT(a,n,-1,r);
    a.set(m);return a;
}
poly qpow(poly a,int b,int n) {
    poly ret;ret.set(n);ret[0]=1;
    while(b) {
        if(b&1) ret=ret*a,ret.set(n);
        a=a*a,a.set(n),b>>=1;
    }
    return ret;
}
int n,m=0,e=0,fac[N],ifac[N];
char a[N],b[N];
int main() {
    scanf("%s",a+1),scanf("%s",b+1),n=strlen(a+1);
    for(int i=1;i<=n;i++) {
        if(a[i]=='1'&&b[i]=='1') ++m;
        else if(a[i]=='0'&&b[i]=='1') ++e;
    }
    fac[0]=1;for(int i=1;i<=n+1;i++) fac[i]=1ll*fac[i-1]*i%mod;
    ifac[n+1]=qpow(fac[n+1],mod-2);
    for(int i=n;i>=0;i--) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
    poly Q;Q.set(m);
    for(int i=0;i<=m;i++) Q[i]=ifac[i+1];
    poly P=qpow(Q,e,m);
    int ans=0;
    for(int i=0;i<=m;i++) ans=(ans+P[i])%mod;
    ans=1ll*fac[e]*fac[m]%mod*fac[e+m]%mod*ans%mod;
    printf("%d\n",ans);
    return 0;
}
