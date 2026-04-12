#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
 
/*** Template Begins ***/
 
typedef unsigned long long    ll;
typedef pair<ll,ll>  pll;
typedef pair<ll, pair<int, int> > plll;
typedef vector<long long>  vll;
typedef vector<pll>  vp;
typedef long double ld;
#define pb           push_back
#define INF          INT_MAX/10
#define F            first
#define S            second
#define mp           make_pair
// #define ios          ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define hell         1000000007
// #define h 998244353
#define all(a)       (a).begin(),(a).end()
ll power(ll x, ll y, ll p)
{
  ll res = 1;
  x = x % p;
  while (y > 0)
  { 
    if (y & 1) 
      res = (res*x) % p;
    y = y>>1;
    x = (x*x) % p;
  } 
  return res; 
} 
const int MAXN = 2e5+5;

// Debug //
#define trace(x)                 cerr << #x << ": " << x << endl;
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
// #define trace6(a, n,i;b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Constants //
 
/*** Template Ends ***/
string s;
ll n;
string t;
ll cache[105][4][2];
ll solve(ll index,ll k,ll flag)
{
  // cout<<t<<endl;
  if(k==0)
  {
    // cout<<t<<" ";
    return 1;
  }
  if(index==n)
  {
    if(k)
      return 0;
    else
    {
      // trace(t);
      return 1;
    }
  }

  if(cache[index][k][flag]!=-1)
    return cache[index][k][flag];
  cache[index][k][flag]=0;
  ll limit,i,newk=k,newflag=flag;
  if(flag)
    limit = 9;
  else
    limit = s[index]-'0';
  for(i=0;i<=limit;i++)
  {
    newflag = flag;
    newk=k;
    if(i!=0)
      newk = k-1;
    if(i<limit)
      newflag=1;
    // trace3(index+1,newk,newflag);
    // t.push_back(i+'0');
    cache[index][k][flag] += solve(index+1,newk,newflag);
    // t.pop_back();
  }
  return cache[index][k][flag];
}
void solve()
{
  cin>>s;
  n = s.length();
  ll k,i,j;
  cin>>k;
  memset(cache,-1,sizeof(cache));
  cout<<solve(0,k,0);
}
int main()
{ 
  // ios;
  // fxreopen("inputt.txt", "w", stdout);
  ll t;
  // cin >> t;
  t=1;
  while(t--)
    solve();
  return 0;
}