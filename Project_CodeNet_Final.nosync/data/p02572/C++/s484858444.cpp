#include "bits/stdc++.h"
#define hhh cerr<<"hhh"<<endl
#define see(x) cerr<<(#x)<<'='<<(x)<<endl
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
inline int read() {int x=0,f=1;char c=getchar();while(c!='-'&&c<48)c=getchar();if(c=='-')f=-1,c=getchar();while(c>47)x=x*10+(c^48),c=getchar();return f*x;}

const int maxn = 3e5+7;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;

ll qpow(ll a,ll k=mod-2,ll p=mod){ll s=1;while(k){if(k&1)s=s*a%p;a=a*a%p;k>>=1;}return s;}

int main() {
    ll s=0, s1=0;
    int n=read();
    for(int i=1; i<=n; ++i) {
        ll a=read();
        s=(s+a)%mod;
        s1=(s1+a*a)%mod;
    }
    cout<<((s*s-s1)%mod+mod)*qpow(2)%mod<<endl;
}