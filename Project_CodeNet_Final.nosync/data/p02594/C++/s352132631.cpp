#include <bits/stdc++.h>
#include <chrono>
#include <random>
#define ll long long int
#define ull unsigned long long int
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
#define loop(i,a,b) for(ll i=a;i<=b;i++)
#define inputv(arr,n) for(ll i=0;i<n;i++){ll value;cin>>value;arr.pb(value);}
#define sz(a) ((ll)(a).size())
#define len(a) ((ll)(a).length())
#define precise cout<<fixed<<setprecision(0); 
#define F first
#define S second
#define vi vector <int> 
#define pll pair<ll,ll>
#define vpll vector<pll>
#define vs vector <string>
#define vc vector <char>
#define vl vector <ll>
#define YES cout<<"Yes\n"
#define NO cout<<"No\n"
#define all(c) (c).begin(),(c).end()
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
#define IOS { ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }
inline ll max(ll a,ll b)
{return ((a>b)?a:b);}
inline ll min(ll a,ll b)
{return ((a>b)?b:a);}
inline ll gcd(ll a ,ll b)
{if(b==0) return a;a%=b;return gcd(b,a);}
#define nl cout<<"\n"
using namespace std;
ll power(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll modInverse(ll a){return power(a,mod-2);}
const int N=500023;
// hashing for pairs
struct HASH{
  size_t operator()(const pair<int,int>&x)const{
    return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
  }
};
//sort in reverse order
bool compare(ll x, ll y){
    return x>y;
}
void solve()
{
  ll x;
  cin>>x;
  if(x>=30)
  {
    YES;
  }
  else
  {
    NO;
  }
  
  return;
}
int main()
{
    IOS;
    int T=1;
   // cin>>T;
    int t=0;
    while(t++<T)
    {
        //cout<<"Case #"<<t<<":"<<' ';
        solve();
        //cout<<'\n';
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}