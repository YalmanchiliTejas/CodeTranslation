#include<bits/stdc++.h>
#define ll long long
#define pii_ pair<int,int>
#define mp_ make_pair
#define pb push_back
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define show1(a) cout<<#a<<" = "<<a<<endl
#define show2(a,b) cout<<#a<<" = "<<a<<"; "<<#b<<" = "<<b<<endl
using namespace std;
const ll INF = 1LL<<60;
const int inf = 1<<30;
const int maxn = 2e5+5;
const ll M = 1e9+7;
inline void fastio() {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
ll qpow(ll a,ll b) {ll s=1;while(b){if(b&1)s=(s*a)%M;a=(a*a)%M;b>>=1;}return s; }
ll fac[maxn],inv[maxn];

void init()
{
    int n = 2e5;
    fac[0] = 1;
    rep(i,1,n) fac[i] = fac[i-1]*i%M;
    inv[n] = qpow(fac[n],M-2);
    per(i,n-1,0) inv[i] = inv[i+1]*(i+1)%M;
}
ll C(ll a,ll b) {return fac[a]*inv[a-b]%M*inv[b]%M;}
int main()
{
    fastio(); init();
    int n,m,k;
    cin>>n>>m>>k;
    ll b = C(n*m-2,k-2);
    ll s = 0,inv2 = qpow(2,M-2);
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            ll a = n * ((j*(j-1)/2 + (1+m-j)*(m-j)/2) % M) % M;
            ll b = m * ((i*(i-1)/2 + (1+n-i)*(n-i)/2) % M) % M;
            s = (s + a + b) % M;
        }
    }
    cout<<b*s%M*inv2%M<<endl;
    return 0;
}
