#include<bits/stdc++.h>
#include<stdio.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
typedef pair<int , int > pii;
#define MOD 1000000007
#define MOD1 998244353
#define ff first
#define ss second
#define bn cout<<"\n"
#define o2(a,b) cout<<a<<" "<<b
#define sz(a) (a).size()
#define o(a) cout << a
#define MAX6 1000006
#define int ll
#define all(x) x.begin(), x.end()
#define ppii pair<int,pii>
#define vi vector<int>
#define vii vector<pii>
#define viii vector<ppii>
#define vs vector<string>
#define pb push_back
#define eb emplace_back
#define endl '\n'
#define MAX5 300005
#define MAX7 10000007
#define rep(i,a,b)  for (__typeof((b)) i=(a);i<=(b);i++)
#define nrep(i,b,a)  for (__typeof((b)) i=(b);i>=(a);i--)
#define mem(a) memset(a,0,sizeof(a))
#define memneg(a) memset(a,-1,sizeof(a))
//#define se second
#define LN 14
#define LIM 22
#define MAX_ALPHA 26
const long long INF64 = 1e18;
const ll INF = 1e9;
const double PI = acos(-1);
#define ld long double
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
inline void max_self(ll &a, ll b)
{
  a = max(a,b);
}
 
inline void min_self(ll &a,ll b)
{
  a = min(a,b);
}
 
inline void add_self(ll &a, ll b) {
  a += b;
  if (a >= MOD) a -= MOD;
}
 
inline void sub_self(ll &a, ll b) {
  a -= b;
  if (a < 0) a += MOD;
}
 
inline int mul(int a, int b) {
  return (int) ((long long) a * b % MOD);
}
 
 
ll gcd(ll a,ll b)
{
  if(b == 0)
    return a;
  else 
    return gcd(b, a%b);
}
 
 
int countDigits(int x)
{
  int cnt = 0;
  while(x)
  {
    x /= 10;
    cnt++;
  }
  return cnt;
}
 
 
ll binExpo(ll a,ll b)
{
  ll res = 1;
  while(b)
  {
    if(b&1)
      res = (res * a)%MOD;
    a = (a * a)%MOD;
    b /= 2;
  }
  return res%MOD;
}
 
int sum(int a) {
    int result = 0;
    while (a > 0) {
        result += a % 10;
        a /= 10;
    }
    return result;
}

const int nax = 3005;

int dp[nax][nax];

void solve()
{
  int n;
  cin>>n;
  vector<int > a(n);
  rep(i, 0, n-1)
    cin>>a[i];
  nrep(L, n-1, 0)
  {
    rep(R, L, n-1)
    {
      if(L == R)
        dp[L][R] = a[L];
      else
        dp[L][R] = max(a[L] - dp[L+1][R], a[R] - dp[L][R-1]);
    }
  }
  cout<<dp[0][n-1]<<endl; 
}
signed main()
{
  

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  //cin>>t;
  while(t--) solve();
  return 0;
}













