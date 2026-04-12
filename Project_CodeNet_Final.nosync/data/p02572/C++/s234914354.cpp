#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define  FIFO ios::sync_with_stdio(false); cin.tie(0);cout.tie(0)
#define  inf 2e18
#define  mod 1000000007
#define  bg begin()
#define  en end()
#define  ll long long int
#define  pb push_back
#define  mp make_pair
#define  pii pair<int,int>
#define  pll pair<ll,ll>
#define  vi vector<int>
#define  vll vector<long long int>
#define  vpll vector<pair<long long int,long long int> >
#define  vpii vector<pair<int,int> >
#define  vstr vector<string>
#define  mpii map<int ,int>
#define  mpll map<long long int,long long int >
#define  max3(v,b,ser) max(v,max(b,ser))
#define  min3(v,b,ser) min(v,min(b,ser))
#define  setbits(x) __builtin_popcountll(x)
#define  zerobits(x) __builtinctzll(x) //zeros after rightmost set bit
#define  w(t) ll t; cin>>t; while(t--)
#define  vin(v,m) for(int i=0;i<m;i++){ll x;cin>>x; v.pb(x);}
#define  for0(i,m) for(int i=0;i<m;i++)
#define  for1(i,m) for(int i=1;i<=m;i++)
#define  forn(i,v,b) for(int i=v;i<=b;i++)
#define  forv(it,v) for(auto it=v.begin();it!=v.end();it++)
#define  mem(v,val) memset(v,val,sizeof(v))
#define  Sort(vec) sort(vec.begin(),vec.end())
#define  RSort(vec) sort(vec.rbegin(),vec.rend())
#define  eb emplace_back
#define  bs binary_search
#define  deb1(x) cerr<<#x<<": "<<x<<" "<<endl
#define  deb2(x, y) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define  deb3(x, y, z) cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define  deb4(v, b, ser, d) cerr<<#v<<": "<<v<<" | "<<#b<<": "<<b<<" | "<<#ser<<": "<<ser<<" | "<<#d<<": "<<d<<endl
#define  FF first
#define  SS second
#define  yes "YES"
#define  no "NO"
#define  PI 3.141592653589793238462643383279502884L
#define printv(v) for(int i=0;i<v.size();i++) cout<<v[i]<<" "
// find_by_order(p)  returns iterator to kth element starting from 0;
// order_of_key(p) returns count of elements strictly smaller than p;
//order of key returns the index if the element was present.(If not present)
template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
ll Ceil(ll v, ll b) {return v / b + (v % b != 0);}
ll Logn(ll m, ll r) {return (m > r - 1) ? 1 + Logn(m / r, r) : 0;}
ll fastModExp(ll v, ll b) { ll res = 1; while (b > 0) { if (b & 1)res = (res * v) % mod; v = (v * v) % mod; b = b >> 1; } return res;}
ll GCD(ll a, ll b) { if (b == 0)return a; else  return GCD(b, a % b);}
//Chrnlgy: Binary Search,Greedy,XY,dfs and similar
ll LCM(ll v, ll b) {return v / GCD(v, b) * b;}


int main()
{
   FIFO;
   ll n;
   cin >> n;
   ll sum[n];
   vll v;
   vin(v, n);
   ll ans = 0;
   sum[0] = v[0];
   for (int i = 1; i < n; i++)
   {
      sum[i] = (sum[i - 1] + v[i]);
   }
   ll sm = sum[n - 1];
   for0(i, n)
   {
      ans = (ans + mod + (((sm - sum[i]) % mod) * v[i]) % mod) % mod;
   }
   cout << ans << endl;
   return 0;
}
