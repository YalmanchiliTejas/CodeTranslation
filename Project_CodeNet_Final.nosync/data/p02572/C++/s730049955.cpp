//  299143BT
#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define mod 998244353
#define pi 3.1415926535
#define fi first
#define se second
#define vll vector<ll>
#define vpll vector<pair <ll,ll> >AC
#define vvll vector< vll >
#define str string
#define umap unordered_map
#define uset unordered_set
#define rep(i,n) for(ll i=0;i<n;i++)
#define repA(i,s,n) for(ll i=s;i<=n;i++)
#define repD(i,s,n) for(ll i=s;i>=n;i--)
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define elif else if
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define sortA(v) sort(ALL(v))
#define sortD(v) sort(ALL(v),greater <ll> ())
#define print(v) for(auto itr:v) cout<<*itr<<" ";
#define sz size()
#define nl cout<<"\n";
using namespace std;
ll factorial(ll n){return (n==1||n==0)?1:n*factorial(n-1);}
ll power(ll x,ll y){ll res=1;while(y>0){if(y&1)res=res*x;y=y>>1;x=x*x;}return res;}
ll powerMod(ll x,ll y,ll m){if(y==0)return 1;ll p=powerMod(x,y/2,m)%m;p=(p*p)%m;return (y%2==0)?p:(x*p)%m;}
ll modInverse(ll a,ll m){return powerMod(a,m-2,m);}
ll gcd(ll a,ll b){if(a==0){return b;}else if(b==0){return a;}else{if(a>b){return gcd(a%b,b);}else{return gcd(b%a,a);}}}

vll v,vsum;

void pre(){

}

void solve(){
   ll n=0;
   cin>>n;
   rep(i,n){
      ll x=0;
      cin>>x;
      v.pb(x);
   }
   vsum.assign(n,0);
   ll ans=0;
   vsum[n-1]=v[n-1];
   repD(i,n-2,0)
       vsum[i]=(vsum[i+1]+v[i])%MOD;
   rep(i,n-1){
       ans=(ans+((v[i]*vsum[i+1])%MOD))%MOD;
   }
   cout<<ans;
}

int main(){

    pre();
    solve();
    return 0;
}