#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<iostream>
# define ll int64_t
# define rep(i,n) for(ll i=0;i<n;i++)
# define rrep(i,n) for(ll i=1;i<=n;i++)
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())
# define pb push_back
# define mod 1000000007
# define vec vector
#define dump(x) cerr<<#x<<"="<<x<<endl
using namespace std;

bool compare_by_b(pair<string,ll> a,pair<string,ll> b){
    if(a.second != b.second) return a.second<b.second;
    else return a.first<b.first;
}

bool my_compare(pair<string,ll> a,pair<string,ll> b){
    
    if(a.first != b.first) return a.first<b.first;
    if(a.second != b.second) return a.second>b.second;
    else return true;
}

ll factorial(ll n){
    ll x=1;
    rrep(i,n) (x*=i)%=mod;
    return x;
}

ll gcd(ll a,ll b)
{
   if (a%b == 0) return(b);
   else return(gcd(b,a%b));
}

ll lcm(ll a,ll b)
{
   return a/gcd(a,b)*b;
}

//累乗だってさ
ll modpow(ll a,ll n,ll mod1) {
    ll res=1;
    while(n>0){
        if(n&1) res=res*a%mod1;
        a = a*a%mod1;
        n >>= 1;
    }
    return res;
}
//逆元だってさ
ll modinv(ll a,ll mod1) {
    return modpow(a, mod1 - 2, mod1);
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll n;
    string ans="";
    vec<ll> mini(26,10000000);
    cin>>n;
    rep(i,n){
        string a;
        cin>>a;
        vec<ll> b(26,0);
        rep(j,a.size()) b[(ll)(a.at(j)-'a')]++;
        rep(i,26) mini[i]=min(mini[i],b[i]);
    }
    rep(i,26){
        while(mini[i]>0){
            ans+=(char)(i+'a');
            mini[i]--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
