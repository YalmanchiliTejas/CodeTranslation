#include <bits/stdc++.h>
using namespace std;
#define ll                      long long
#define pb                      push_back
#define rep(i,a,b,c)            for(ll i=(a);i<=(b);i+=(c))
#define repb(i,a,b,c)           for(ll i=(a);i>=(b);i-=(c))
#define MOD                     1000000007
#define inf                     3e18
#define ld                      long double
#define mp                      make_pair
#define vpll                    vector<pair<ll,ll> >
#define vll                     vector<ll>
#define vld                     vector<ld>
#define vvll                    vector<vector<ll>>
#define vvld                    vector<vector<ld>>
#define pll                     pair<ll,ll>
#define vvpll                   vector<vector<pair<ll,ll>>>
#define pqll                    priority_queue<ll>
#define mll                     map<ll,ll>
#define mlc                     map<ll,char>
#define um                      unordered_map
#define umll                    um<ll,ll>
#define umlc                    um<ll,char>
#define all(x)                  x.begin(),x.end()
#define fi                      first
#define se                      second
#define ln                      cout<<"\n";
#define endl                    "\n"
#define test                    ll T;cin>>T;while(T--)
#define isvowel(a)              (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
#define fastIO                  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define show(w,size)            for(ll i=0;i<size;i++) cout<<w[i]<<" ";
#define prll(a)                 cout<<a<<"\n";
#define mset(dp,no)             memset(dp,no,sizeof(dp))
#define input(a,n)              rep(i,0,n-1,1) cin>>a[i];
#define countbit                __builtin_popcount                                           //Number of setbits in decimal notation
#define lb(v,cur)               lower_bound(all(v),cur)-v.begin()
#define ub(v,cur)               upper_bound(all(v),cur)-v.begin()
#define db(...)                 __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 <<'\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
long long pows(long long a, long long b) {
  long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
ll powm(ll x,ll y,ll m=MOD){x=x%m;ll res=1;while(y){if(y&1)res=res*x;res%=m;y=y>>1;x=x*x;x%=m;}return res;}
ll modInverse(ll a, ll m=MOD){return powm(a,m-2,m);}
int main()
{
fastIO
ll n,m,i,j,k,x,y,z,t,e,f,p,q,g,l,r,o,w,h,count1=0,prod=1,a,b,c,d,index,x1,x2,y1,y2,diff,ans=0,sum=0,sum1=0,sum2=0,flag=0,flag1=0,flag2=0;
string s,s1,s2;
cin>>n;
ll ar[n],pre[n];
for(i=0;i<n;i++)
{
  cin>>ar[i];
}
pre[0]=ar[0];
for(i=1;i<n;i++)
{
  pre[i]=pre[i-1];
  pre[i]+=ar[i];
  pre[i]%=MOD;
}
sum=pre[n-1];
for(i=0;i<n;i++)
{
  sum-=ar[i];
  sum+=MOD;
  sum%=MOD;
  ans+=(sum*ar[i])%MOD;
  ans%=MOD;
}
cout<<ans;
}
