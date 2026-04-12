//author: chinmay0402
#include<bits/stdc++.h>
using namespace std;
//policy based data structures
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

#define ll long long int
#define ld long double
#define fl float
#define vs vector<string>
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pair<ll,ll>>
#define fst first
#define scd second
#define sll set<ll>
#define mll map<ll,ll>
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define INF (ll)10000000000000000
#define MOD (ll)1000000007
#define pb push_back
#define msl map<string,ll>
#define test ll t;cin>>t;while(t--)
#define sortv(v) sort(v.begin(),v.end())
#define max3(a,b,c) max(a,max(b,c))
#define lcm(a,b) (a*b/__gcd(a,b))
#define all(a) a.begin(),a.end()
#define sz(a) a.size()
#define present(c,x) (c.find(x)!=c.end());
#define c_sum accumulate(all(c),(ll)0);
#define count_ones(x) __builtin_popcountll(x)
#define doom cout<<"doom\n"
#define debug(x) cerr<<#x<<"->"<<x<<"\n";

#define forn(i,n) for(ll i=0;i<n;i++)
#define for1(i,n) for(ll i=1;i<=n;i++)
#define fornr(i,n) for(ll i=n-1;i>=0;i--)
#define forab(i,a,b,c) for(ll i=a;i<=b;i+=c)

template<typename T>
void read(T &x){
 cin>>x;
}
template<typename T,typename T1>
void read(T &x, T1 &y){
 cin>>x>>y;
}
template<typename T,typename T1, typename T2>
void read(T &x, T1 &y, T2 &z){
 cin>>x>>y>>z;
}
template<typename T,typename T1, typename T2, typename T3>
void read(T &x, T1 &y, T2 &z , T3 &a){
 cin>>x>>y>>z>>a;
}
template<typename T>
void reada(T oneD,ll n){
 for(ll i=0;i<n;i++)
  cin>>oneD[i];
}
template <typename T>
void readv(vector< T > &oneD,ll n){
 forn(i,n){
  ll x;
  read(x);
  oneD.push_back(x);
 }
}
template<typename T>
void readg(vector< T >graph[100001], ll n){
 forn(i,n){
  ll x,y;
  cin>>x>>y;
  graph[x].pb(y);
  graph[y].pb(x);
 }
}

#define iread1(n) ll n;read(n);
#define iread2(n,m) ll n,m;read(n,m);
#define iread3(x,y,z) ll x,y,z;read(x,y,z);

ll gcd(ll a, ll b){
 if(a==0)
  return b;
 else
  return gcd(b%a,a);
}

ll gcdExt(ll a,ll b, ll &x, ll &y){
 if(a==0){
  x=0;
  y=1;
  return b;
 }
 ll x1,y1;
 ll gcd=gcdExt(b%a,a,x1,y1);
 x=y1-(b/a)*x1;
 y=x1;
 return gcd;
}

ll pwr(ll a, ll b){
 ll res=1;
 while(b>0){
  if(b&1)
   res=res*a;
  a*=a;
  b>>=1;
 }
 return res;
}

ll pwrm(ll a, ll b, ll m){
 a%=m;
 ll res=1;
 while(b>0){
  if(b&1)
   res=res*a%m;
  a=a*a%m;
  b>>=1;
 }
 return res;
}

ll pwrm_which_works_too(ll a, ll b, ll m){
 a%=m;
 if(a==0)
  return 0;
 else if(b==0)
  return 1;
 else if(b&1)
  return (a*pwrm(a,b/2,m)%m*pwrm(a,b/2,m)%m)%m;
 else
  return (pwrm(a,b/2,m)%m*pwrm(a,b/2,m)%m)%m;
}

vector<bool>sieve(1000000,true);
void Sieve(){
 sieve[0]=false;
 sieve[1]=false;
 for(ll i=2;i*i<=1000000;i++){
  if(sieve[i]==true){
   for(ll j=i*i;j<1000000;j+=i)
    sieve[j]=false;
  }
 }
}

vll sieve_spf(10000001);
void Sieve_spf(){
 ll n=10000000;
 
 forn(i,n)
  sieve_spf[i]=i;
 
 sieve_spf[0]=-1;
 sieve_spf[1]=-1;
 
 forab(i,2,n,2)
  sieve_spf[i]=2;
 
 forab(i,3,n,2)
  if(sieve_spf[i]==i)
   forab(j,i*i,n,i)
    if(sieve_spf[j]==j)
     sieve_spf[j]=i;
}

bool oppositeSigns(ll x,ll y) 
{ 
  return ((x^y)<0); 
} 

bool isInt(ll a, ll b){
 if((ld)a/(ld)b==a/b)
  return true;
 else
  return false;
}

struct CustomComp {
  bool operator() (const ll& a, const ll& b) const
  {return a<b;}  // {return a<b;} can be replaced by {return f(a)<f(b);}
  // Usage:set<ll,CustomComp>s;   and similarly for maps, etc.
};

// Lambda expression for custom sort
auto comp = [](ll a, ll b) { return a < b; }; // {return a<b;} can be replaced by {return f(a)<f(b);}
// Usage : map<ll,ll,decltype(comp)>mp(comp);    and similarly for set, etc;

ll modInv(ll a,ll p){ //Only when p is prime
 return pwrm(a,p-2,p);
}

ll compute_hash(const string& s,vll &hashv){
 ll p=31;
 ll m=1e9+9;
 ll hash_value=0;
 ll p_pow=1;
 ll i=0;
 for(char c:s){
  hash_value=(hash_value+(c-'a'+1)*p_pow)%m;
  p_pow=(p_pow*p)%m;
  hashv.pb(hash_value);
 }
 return hash_value;
}

ll compute_alt_hash(const string& s,vll &hashalt){
 ll p=53;
 ll m=1e9+7;
 ll hash_value=0;
 ll p_pow=1;
 ll i=0;
 for(char c:s){
  hash_value=(hash_value+(c-'a'+1)*p_pow)%m;
  p_pow=(p_pow*p)%m;
  hashalt.pb(hash_value);
 }
 return hash_value;
}

vll powmi_p;
void precalc_modInv_p(ll n){
 ll m=1e9+9;
 ll i=1;
 ll k=1;
 ll p=31;
 while(i<=n){
  powmi_p.pb(modInv(k,m));
  k=(k*p)%m;
  i++;
 }
}

vll powmin_p;
void precalc_modinv_p(ll n){
 ll m=1e9+7;
 ll i=1;
 ll k=1;
 ll p=53;
 while(i<=n){
  powmin_p.pb(modInv(k,m));
  k=(k*p)%m;
  i++;
 }
}

ll no_of_divisors(ll n){ 
 ll c = 0; 
 for (ll i = 1; i <= sqrt(n); i++) { 
  if (n % i == 0){ 
   if(n/i==i)
    c=c+1;
   else
    c=c+2;
  }
 }
 return c; 
}

ll dp[3002][3002][2];
ll a[3001];
ll solve(ll l,ll r,ll player){
 if(r<l)
  return 0;
 if(dp[l][r][player%2]!=-1)
  return dp[l][r][player%2];
 return dp[l][r][player%2]=max(a[l]-solve(l+1,r,(player+1)%2),a[r]-solve(l,r-1,(player+1)%2));
}

int main(){

 // Work like there is someone working 24 hours a day to take it all away from you.

 #ifdef ENABLE_FILE_IO
 freopen("in", "r", stdin);
 freopen("out", "w", stdout);
 #endif

 // g++ -std=c++17 -Wshadow -Wall -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -o 

 //START OF PROGRAM LOGIC
 ll n;
 cin>>n;
 memset(dp,-1,sizeof(dp));
 reada(a,n);
 cout<<solve(0,n-1,1)<<"\n";
 //END OF PROGRAM LOGIC
 cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
 return 0;
}
