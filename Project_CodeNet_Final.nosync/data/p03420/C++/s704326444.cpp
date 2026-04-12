#include <bits/stdc++.h>
using namespace std;
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
const ll mod =1e18;
const ll MAX_NODES =200001;
const ll MAX_LOG =50;
const ll maxn = 400000+10;
const int K = 31;
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
  int n,k;
  cin>>n>>k;
  int ans = 0;
  for(int b = 1;b<=n;b++){
    if(k>=b)
      continue;
    int rem = n%b;
    int completes = n/b;
    ans+=(b-k)*completes;
    if(k==0)
      ans--;
    ans+=(max(0ll,rem-k+1));
  }
  cout<<ans<<endl;
}
