#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
const int mo=998244353;
const int gx=3;
const int N=40000;
const int M=200;
int Sum(int x,int y) {
    x+=y;
    return (x>=mo)?x-mo:x;
}
int Sub(int x,int y) {
    x-=y;
    return (x<0)?x+mo:x;
}
int Mul(int x,int y) {
    return (long long)x*y%mo;
}
int Pow(int x,int y=mo-2) {
    int z=1;
    while (y) {
        if (y&1) z=Mul(z,x);
        y>>=1;
        x=Mul(x,x);
    }
    return z;
}
int f[M+10][8000+10],fac[N+10],inv[N+10],f1[N+10],g1[N+10];
int n,m;
namespace Conv {
    int rev[N+10],wx[N+10];
    int lst=1;
    void Pre(int n) {
        rev[0]=0;
        for (int i=1;i<n;i++)
            if (i&1) rev[i]=rev[i^1]+(n>>1);
            else rev[i]=rev[i>>1]>>1;
        for (;lst<n;lst<<=1) {
            int wn=Pow(gx,(mo-1)/(lst<<1));
            for (int i=lst,now=1;i<(lst<<1);i++,now=Mul(now,wn))
                wx[i]=now;
        }
    }
    void Dft(int *a,int n) {
        for (int i=0;i<n;i++)
            if (i<rev[i]) swap(a[i],a[rev[i]]);
        for (int i=2;i<=n;i<<=1)
            for (int j=0;j<n;j+=i) {
                int *l=a+j,*r=a+j+i/2,*now=wx+i/2;
                for (int k=0;k<i/2;k++,l++,r++,now++) {
                    int va1=*l,va2=Mul(*r,*now);
                    *l=Sum(va1,va2);
                    *r=Sub(va1,va2);
                }
            }
    }
    void Idft(int *a,int n) {
        Dft(a,n);
        reverse(a+1,a+n);
        int invn=Pow(n);
        for (int i=0;i<n;i++)
            a[i]=Mul(a[i],invn);
    }
}
void Prework() {
    fac[0]=1;
    for (int i=1;i<=N;i++) fac[i]=Mul(fac[i-1],i);
    inv[N]=Pow(fac[N]);
    for (int i=N-1;i>=0;i--) inv[i]=Mul(inv[i+1],i+1);
}
void Calc(int x) {
    int nx=1;
    while (nx<=n*2) nx<<=1;
    for (int i=0;i<nx;i++) f1[i]=g1[i]=0;
    for (int i=0;i<=n;i++)
        f1[i]=Mul(f[x][i+2],inv[i]);
    for (int i=0;i<=n;i++)
        g1[i]=inv[i];
    Conv::Pre(nx);
    Conv::Dft(f1,nx);
    Conv::Dft(g1,nx);
    for (int i=0;i<nx;i++) f1[i]=Mul(f1[i],g1[i]);
    Conv::Idft(f1,nx);
}
void Solve() {
    for (int i=0;i<=n;i++) f[0][i]=1;
    for (int i=1;i<=m;i++) {
        f[i][0]=1;
        for (int j=1;j<=n;j++)
            f[i][j]=Sub(Mul(f[i-1][j],j+1),Sum(Mul(f[i-1][j+1],j),f[i-1][j+2]));
        Calc(i-1);
        for (int j=1;j<=n;j++)
            f[i][j]=Sum(f[i][j],Mul(f1[j],fac[j]));
    }
    printf("%d\n",f[m][n]);
}
int main() {
    Prework();
    scanf("%d%d",&n,&m);
    Solve();
    return 0;
}
