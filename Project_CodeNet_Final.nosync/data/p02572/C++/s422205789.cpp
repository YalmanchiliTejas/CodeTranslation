#include<bits/stdc++.h>
using namespace std;
typedef       long long int      ll;
#define       READ               freopen("in.txt", "r", stdin);
#define       WRITE              freopen("out.txt", "w", stdout);
#define       optimize           ios::sync_with_stdio(0);cin.tie(0);
#define       RESET(a, b)        memset(a, b, sizeof(a))
#define       gcd(a, b)          __gcd(a, b)
#define       MX                 300005
#define       MOD               1000000007
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p & 1LL) r = modMul(r, b); b = modMul(b, b); p >>= 1LL; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }
bool cmp(ll x,ll y)
{
   return x>y;
}
int main(void)
{
   optimize
   long long int t,n,m,k,x,y,a[200001];
   vector<ll> v,v1,v2;
   vector< pair <ll,ll> >p,p1,p2;
   set<ll> st;
   priority_queue<ll> pq;
   priority_queue< ll,vector<ll>,greater<ll> > lpq;
   priority_queue< pair<ll,ll> > phpq;
   priority_queue< pair<ll,ll>,vector< pair<ll,ll> >,greater< pair <ll,ll> > > plpq;
   string s;
   //cin>>t;
   //while(t--)
   //{
      cin>>n;
      for(ll i=0;i<n;i++)
      {
         cin>>a[i];
      }
      sort(a,a+n);
      ll ans=0,sum=0;
      for(ll i=0;i<n-1;i++)
      {
         sum=modAdd(sum,a[i]);
         ans=modAdd(ans,modMul(sum,a[i+1]));
      }
      cout<<ans<<endl;
   //}
   return 0;
}
