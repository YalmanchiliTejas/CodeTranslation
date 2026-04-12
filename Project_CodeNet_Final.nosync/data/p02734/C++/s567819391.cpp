//#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
// template <class c, class cmp = less<c> > using ordered_set = tree<c, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;



  #define IOS ios_base::sync_with_stdio(false);cin.tie(NULL); 

  #define ff first
  #define ss second
  #define pb push_back
  #define pf push_front
  #define mp make_pair
  #define in insert
  #define ld long double


  #define TRACE
  #ifdef TRACE
  #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
  template <typename Arg1>
  void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
  }
  template <typename Arg1, typename... Args>
  void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
  }
  #else
  #define trace(...) 1
  #endif
  template<class T> ostream& operator<<(ostream &os, vector<T> V) {os << "[ "; for(auto v : V) os << v << " "; return os << "]";}
  template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {return os << "(" << P.first << "," << P.second << ")";}
  template <typename T,typename U>pair<T,U> operator+(const pair<T,U> & l,const std::pair<T,U> & r) { return {l.first+r.first,l.second+r.second};}
  typedef long long int ll;

  typedef vector<int> vi;
  typedef vector<ll> vl;
  typedef vector<vi> vvi;
  typedef vector<vl> vvl;
  typedef pair<int,int> pii;
  typedef pair<ll,ll> pll;
  typedef vector<pii> vpii;
  typedef vector<pll> vpll;
  #define int ll
  const ll mod =998244353;
  const ll MAX_NODES =200001;
  const ll MAX_LOG =50;
  const ll maxn = 400000+10;
  #define endl '\n'
  ll power(ll x, ll n) {
	ll res = 1;
	for (; n > 0; n >>= 1) {
	if (n & 1) res = (res * x) % mod;
	x = (x * x) % mod;
	}
	return res;
}
  int32_t main()
{

  IOS
  int n,s;
  cin>>n>>s;
  int a[n];
  for(int i = 0;i<n;i++)
  {
    cin>>a[i];
  }
  int ans = 0;
  
  vector<vl>dp(n+1,vector<int>(s+2,0));
  dp[0][0] = 1;
  for(int i = 0;i<n;i++)
  {   
    for(int j = 0;j<=s+1;j++)
    {
      dp[i+1][j]= dp[i][j];
    }
    dp[i+1][0]++;
    for(int j = a[i];j<=s+1;j++)
    {
      dp[i+1][j]+=dp[i][j-a[i]];
      dp[i+1][j]%=mod;
    }
    ans+=(dp[i+1][s]);
    ans%=mod;
  }
    
  
  cout<<ans<<endl;
  
  
  
 
  
}
