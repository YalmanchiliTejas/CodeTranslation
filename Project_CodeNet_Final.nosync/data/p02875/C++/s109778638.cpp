#include<bits/stdc++.h>
using namespace std;

void read(int &x) {
    x=0;int f=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-f;
    for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';x*=f;
}

void print(int x) {
    if(x<0) putchar('-'),x=-x;
    if(!x) return ;print(x/10),putchar(x%10+48);
}
void write(int x) {if(!x) putchar('0');else print(x);putchar('\n');}

#define lf double
#define ll long long 

#define pii pair<int,int >
#define vec vector<int >

#define pb push_back
#define mp make_pair
#define fr first
#define sc second

#define data asd09123jdf02i3h

#define FOR(i,l,r) for(int i=l,i##_r=r;i<=i##_r;i++)

const int maxn = 1e7+10;
const int inf = 1e9;
const lf eps = 1e-8;
const int mod = 998244353;

int n,fac[maxn],ifac[maxn],inv[maxn];

int c(int a,int b) {return 1ll*fac[a]*ifac[b]%mod*ifac[a-b]%mod;}

int qpow(int a,int x) {
    int res=1;
    for(;x;x>>=1,a=1ll*a*a%mod) if(x&1) res=1ll*res*a%mod;
    return res;
}

int main() {
    read(n);fac[0]=ifac[0]=inv[0]=inv[1]=1;
    for(int i=2;i<=n;i++) inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod,ifac[i]=1ll*ifac[i-1]*inv[i]%mod;
    int ans=qpow(3,n);
    for(int i=n/2+1;i<=n;i++) ans=(ans-2ll*qpow(2,n-i)*c(n,i)%mod+mod)%mod;
    write(ans);
    return 0;
}
