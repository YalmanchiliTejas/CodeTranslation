#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define f first
#define se second
#define pb push_back
#define ms memset
#define MOD 1000000007
#define MOD2 1000000009
#define sp fixed<<setprecision
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
ll fpow(ll x,ll y,ll p=MOD){x=x%p;ll sum=1;while(y){if(y&1)sum=sum*x;sum%=p;y=y>>1;x=x*x;x%=p;}return sum;}
ll inv(ll a,ll m=MOD){ll c=m;ll y=0,x=1;if(m==1)return 0;while(a>1){ll q=a/m;ll t=m;m=a%m,a=t;t=y;y=x-q*y;x=t;}if(x<0)x+=c;return x;}
ll add(ll a, ll b) {if(a<0)a+=MOD; if(b<0)b+=MOD; return (a%MOD + b%MOD + MOD)%MOD;}
ll sub(ll a, ll b) {if(a<0)a+=MOD; if(b<0)b+=MOD; return (a%MOD - b%MOD + MOD)%MOD;}
ll mul(ll a, ll b) {if(a<0)a+=MOD; if(b<0)b+=MOD; return ((a%MOD)*(b%MOD) + MOD)%MOD;}
void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (sz(name)) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}
ll spf[1000005];
int main(){
    setIO();
    ll n,x,m;
    cin>>n>>x>>m;
    vector<ll>v;
    ll sum = x;
    ll seed  = x;
    map<ll,ll>memo;
    memo[x]=1;
    v.pb(x);
    for(int i=2;i<=min(m,n);i++){
      seed  = (seed*seed)%m;
      if(memo[seed]){
        ll len = i-memo[seed];
        //v.pb(seed);
        //sum+=seed;
        ll rem = n-i+1;
        ll q=rem/len;
        ll r =rem%len;
        ll tmp = 0;
        for(int j=memo[seed]-1;j<v.size();j++)
          tmp+=v[j];
        sum+=tmp*q;
        for(int j=memo[seed]-1;j<memo[seed]-1+r;j++)
          sum+=v[j];
        break;
      }
      memo[seed]=i;
      v.pb(seed);
      sum+=seed;
    }


    cout<<sum;

}
