
/*
LANG:C++
PROB:

*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <iostream>
// #define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)


using namespace __gnu_pbds;
using namespace std;


typedef tree<int, null_type, less<int>, rb_tree_tag,
            tree_order_statistics_node_update>
    ordered_set;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;
typedef unsigned long long ui64;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }
const int mod=1000000007;
  i64 poww(i64 a, i64 b)
  {
    a%=mod;
    i64 res=1;
    while(b)
      {
if(b&1)res=res*a%mod;

      a=a*a%mod;
      b/=2;

      }
      return res;
  }
  i64 inv(i64 a)
  {
    return poww(a,mod-2);
  }
  void solve()
  {
i64 sum=0;
int n;
cin>>n;
vi64 v(n);
forn(i,n){cin>>v[i];sum+=v[i];}
sum%=mod;

i64 ans=0,pre=0;
forn(i,n)
{
ans+=(v[i])*(sum-v[i]);
sum-=v[i];
sum%=mod;
ans%=mod;
}
if(ans<0)ans+=mod;
cout<<ans;

  }
  
  int main()
  {
ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
    #endif
int t=1;
while(t--)
{
  solve();
}

    return 0;
  }
