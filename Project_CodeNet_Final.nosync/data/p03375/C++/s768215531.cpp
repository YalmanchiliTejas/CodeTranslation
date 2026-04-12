#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define rer(i, a, b) for(int i = int(a) - 1; i >= int(b); i--)
#define sz(v) (int)(v).size()
#define pb push_back
#define sc second
#define fr first
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
using namespace std;
typedef long long int ll;
typedef pair <int, int> P;
ll mod_pow(ll x, ll n, ll mod){
    if (n==0) return 1;
    ll res=mod_pow(x*x%mod, n/2, mod);
    if (n%2==1) res=res*x%mod;
    return res;
}
ll euler_phi(ll n){
    ll res=n;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            res=res/i*(i-1);
            for(;n%i==0;n/=i);
        }
    }
    if(n!=1) res=res/n*(n-1);
    return res;
}
ll extgcd(ll a, ll b, ll& x, ll&y){
    ll d=a;
    if(b!=0){
        d=extgcd(b, a%b, y, x);
        y-=(a/b)*x;
    }
    else {
        x=1; y=0;
    }
    return d;
}
ll mod_inverse(ll a, ll m){
    ll x,y;
    extgcd(a,m,x,y);
    return (m+x%m)%m;
}
ll fact[3010];
ll mod_fact(ll n, ll p, ll& e){
    e=0;
    if(n==0) return 1;
    ll res=mod_fact(n/p,p,e);
    e+=n/p;
    if(n/p%2!=0) return res*(p-fact[n%p])%p;
    return res*fact[n%p]%p;
}
ll mod_comb(ll n, ll k, ll p){
    if(n<0||k<0||n<k) return 0;
    ll e1, e2, e3;
    ll a1=mod_fact(n,p,e1), a2=mod_fact(k,p,e2), a3=mod_fact(n-k,p,e3);
    if(e1>e2+e3) return 0;
    return a1*mod_inverse(a2*a3%p,p)%p;
}
ll dp[3010][3010];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N,M;
    cin>>N>>M;
    dp[0][0]=1;
    rep(i,1,N+1){
        rep(j,0,i+1){
            if(j>0) dp[i][j]+=dp[i-1][j-1];
            dp[i][j]+=dp[i-1][j]*(j+1)%M;
            dp[i][j]%=M;
        }
    }
    ll a[3010]={};
    rep(i,1,N+1){
        ll s=0;
        rep(j,0,i+1){
            s+=dp[i][j]*mod_pow(2,(N-i)*j,M)%M;
            s%=M;
        }
        s*=mod_pow(2, mod_pow(2,N-i,M-1), M);
        s%=M;
        a[i]=s;
    }
    fact[1]=1;
    rep(i,2,3010){
        fact[i]=fact[i-1]*i;
        fact[i]%=M;
    }
    ll ans=0;
    rep(i,1,N+1){
        ans+=mod_comb(N, i, M)*a[i]*(i%2?1:-1);
        ans%=M;
    }
    ans=((mod_pow(2,mod_pow(2,N,M-1),M)-ans)%M+M)%M;
    cout <<ans<<"\n";
}