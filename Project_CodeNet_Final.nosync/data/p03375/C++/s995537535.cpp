#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define PB push_back
#define MP make_pair
#define FIR first
#define SEC second
#define ll long long
using namespace std;
template <class T>
inline void rd(T &x) {
	x=0; char c=getchar(); int f=1;
	while(!isdigit(c)) { if(c=='-') f=-1; c=getchar(); }
	while(isdigit(c)) x=x*10-'0'+c,c=getchar(); x*=f;
}
const int N=3010;
int mod;
int Pow(int x,int y) {
    int res=1;
    while(y) {
        if(y&1) res=res*(ll)x%mod;
        x=x*(ll)x%mod,y>>=1;
    }
    return res;
}
int Pow(int x,int y,int mod) {
    int res=1;
    while(y) {
        if(y&1) res=res*(ll)x%mod;
        x=x*(ll)x%mod,y>>=1;
    }
    return res;
}
int C[N][N],n;
int pw[N*N];
int f[N][N];
int main() {
    rd(n),rd(mod);
    for(int i=0;i<=n;++i) for(int j=0;j<=i;++j) C[i][j]=j?(C[i-1][j-1]+C[i-1][j])%mod:1;
    pw[0]=1; for(int i=1;i<=n*n;++i) pw[i]=pw[i-1]*2ll%mod;

    f[0][0]=1;
    for(int i=1;i<=n;++i)
        for(int j=0;j<=i;++j)
            f[i][j]=(f[i-1][j]*(ll)(j+1)+f[i-1][j-1])%mod;
    int ans=0;
    for(int i=0;i<=n;++i) {
        int tot=0;
        for(int j=0;j<=i;++j) tot=(tot+f[i][j]*(ll)pw[(n-i)*j]%mod)%mod;
        tot=tot*(ll)Pow(2,Pow(2,n-i,mod-1))%mod;
        ans=(ans+C[n][i]*(ll)tot*((i&1)?-1:1))%mod;
    }
    printf("%d",(ans+mod)%mod);
    return 0;
}