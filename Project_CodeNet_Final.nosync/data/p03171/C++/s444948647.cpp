#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
// typedef tree<int,int,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_map;
#define ll long long
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define si size()
#define bk back()
#define popb pop_back()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
#define emp empty()
#define beg begin()
#define en end()
#define ump unordered_map
#define forl(i,a,n) for(int i=a;i<n;i++)
#define rfor(i,n,a) for(int i=n;i>=a;i--)
#define fore(i,a,n) for(int i=a;i<=n;i++)
#define len length()
#define ld long double
//use (__int128)to extend ll range
// cout<<__builtin_popcountll(10)<<endl; //number of 1
// cout<<__builtin_parityll(6)<<endl;//(number of 1)mod(2)
// cout<<__builtin_clzll(10)<<endl;//number of zeros at beginning (64 bit rep) 
// cout<<__builtin_ctzll(8)<<endl;//number of zeros at end (64 bit rep) 
const long double PI=3.14159265358979323846;
double doINF = 1.0/0.0 ;
ostream_iterator <int> outp(cout," ");
inline ll modadd(ll n,ll m,ll mod){
    ll sum = (((n%mod)+(m%mod))%mod+mod)%mod;
    return sum;
} 
inline ll modsub(ll n,ll m, ll mod){
    ll diff = (((n%mod)-m+mod)%mod+mod)%mod;
    return diff;
}
inline ll modpro(ll n,ll m,ll mod){
    ll pro = ((((n+mod)%mod)*((m+mod)%mod)+mod)%mod+mod)%mod;
    return pro;
}
inline ll pow(int x,int y){
    ll res = 1;
    while (y > 0) {
        if (y & 1)
            res = res * x;
        y = y >> 1;
        x = x * x;
    }
    return res;
}
inline ll powmod(ll x,ll y,ll mod){
    ll res = 1;
    while (y > 0) {
        if (y & 1)
            res = modpro(res , x,mod);
        y = y >> 1;
        x = modpro(x , x,mod);
    }
    return res;
}
ll min(ll a, ll b){
if(a>b){
    return b;
}
return a;
}

ll max(ll a, ll b){
if(a>b){
    return a;
}else return b;
}

bool pairdec(const pair<int,int> &a,  
            const pair<int,int> &b) 
{ 		if(a.fi!=b.fi)
        return (a.fi> b.fi);
        else return a.se>b.se;  
} 
ll power(ll x, ll y, ll mod) 
{ 
    ll res = 1; 
    x = (x+mod)%mod; 
    while (y > 0) { 
        if (y & 1) 
            res =modpro(res,x,mod); 

        y = y >> 1;
        x =modpro(x,x,mod); 
    } 
    return res; 
} 


ll modInverse(ll a, ll mod) 
{ 
    return  powmod(a, mod - 2, mod); 
} 
ll modFact(ll n, ll mod) 
{ 
    if (n >=mod) return 0; 

    ll result = 1; 
    for (ll i = 1; i <= n; i++) 
        result = (result * i) %mod; 

    return result; 
} 
ll modcomb(ll n,ll r, ll mod) 
{ 
if (r==0) return 1; 
ll val1=modFact(n,mod);
ll val2=modInverse(modFact(r,mod),mod);
ll val3=modInverse(modFact(n-r,mod),mod);
ll val4=modpro(val1,val2,mod);
return modpro(val4,val3,mod);
} 
//modular inverse for 1 to n(Extended Euclid Algo)
void modInverse2(ll n,ll mod)
{
    ll dp[n+1];
    dp[0]=dp[1]=1;
    fore(i,2,n)
    {
        dp[i]=dp[mod%i]*((mod-mod/i)%mod);
    }
}
//cout<<setprecision(9)<<fixed<<sum<<endl; --- precision for double numbers
bool comp(const pair<int,int>pia,const pair<int,int>pib)
{
    if(pia.fi==pib.fi) return pia.se<=pib.se;
    else return pia.fi<pib.fi;
}
const ll mod=1e9+7;
int main()
{
  int n;
  cin>>n;
  ll arr[n];
  forl(i,0,n) cin>>arr[i];
  ll dp[n][n];
  for(int l=1;l<=n;l++)
  {
      fore(i,0,n-l)
      {
          int j=i+l-1;
          if(l==1) dp[i][j]=arr[i];
          else{
              dp[i][j]=max(arr[i]-dp[i+1][j],arr[j]-dp[i][j-1]);
          }
      }
  }
  cout<<dp[0][n-1]<<endl;
   
    
}