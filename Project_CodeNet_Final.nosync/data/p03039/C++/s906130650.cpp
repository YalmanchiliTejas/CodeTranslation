#include <bits/stdc++.h>
#define rep(i, a, b) for(ll i = ll(a); i < ll(b); i++)
#define rer(i, a, b) for(ll i = ll(a) - 1; i >= ll(b); i--)
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

const ll MOD=1000000007;
ll N,M,K;
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
ll mod_inverse(ll a, ll m=MOD){
    ll x,y;
    extgcd(a,m,x,y);
    return (m+x%m)%m;
}
const int MAX_N=300000;
ll fact[MAX_N], invfact[MAX_N];
ll comb(ll a, ll b){
    return fact[a]*invfact[b]%MOD*invfact[a-b]%MOD;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M>>K;
    ll res=0;
    rep(i,0,M-1){
        ll t=N*(i+1), u=N*(M-i-1);
        res+=t*(t-1)+u*(u-1);
        res%=MOD;
    }
    rep(i,0,N-1){
        ll t=M*(i+1), u=M*(N-i-1);
        res+=t*(t-1)+u*(u-1);
        res%=MOD;
    }
    fact[0]=1;
    invfact[0]=1;
    rep(i,1,MAX_N){
        fact[i]=fact[i-1]*i%MOD;
        invfact[i]=mod_inverse(fact[i]);
    }
    res=N+M-2-res*mod_inverse(N*M*(N*M-1))%MOD;
    res=(res%MOD+MOD)%MOD;
    ll x=comb(N*M,K);
    res*=comb(N*M, K)*comb(K,2)%MOD;
    cout <<(res+MOD)%MOD<<"\n";
}