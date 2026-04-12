#include <bits/stdc++.h>
using namespace std;
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os << "[ "; 
  for(auto v:V)os << v << " "; return os << "]";
}
template<class T> ostream& operator<<(ostream &os, set<T> S){ os << "{ "; 
  for(auto s:S) os<<s<<" ";  return os<<"}"; 
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
  return os<<"("<<P.first<<","<< P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
  os<<"{ ";for(auto m:M)os<<"("<<m.first<<":"<<m.second<<")";
  return os<<"}";
}
#define cerr cout
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
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
//For multiset use less_equal operator but it does support erase operations for multiset
#define ll long long
#define ld long double
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define I insert 
#define pb push_back
#define F first
#define S second
//#define endl "\n"
#define all(v) (v).begin(),(v).end()
#define For(i,n) for(int i=0;i<(int)n;++i)
#define Rev(i,n) for(int i=(int)n-1;i>=0;--i)
#define Rep(i,n) for(int i=1;i<=(int)n;++i)
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef vector<pii> vpi;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mp make_pair
// inline void modadd(int &a,int &b){a+=b;if(a>=mod)a-=mod;} 
const int N = 1e6;
ll dp[N];
int lst[N];
int main(){
  fio; cout<<fixed<<setprecision(25);	
  ll n , x , m ; cin >> n >> x >> m;
  ll tmp = x;
  ll ans = 0; 
  ll i = 0;
  bool ok = 0;
  while(1){
    ++i;
    if(lst[x] != 0) break;
    lst[x] = i;
    dp[i] = x;
    x = x*x%m;
    if(x == 0){
      ok = 1;
      break;
    }
  }
  if(n < N){
    ll ans = 0;
    for(int i = 1;i <= n ; ++i){
      ans += tmp;
      tmp =tmp*tmp%m;
    }
    cout << ans << endl;
    return 0;
  }
  if(ok){
    for(int j = 1;j <= min(n,i*1ll) ; ++j)
      ans += dp[j];
    cout << ans << endl;
  }
  else{
    ll q = 0;
    while(1){
      ++q;
      if(tmp != x) ans += dp[q];
      else break;
      tmp = tmp*tmp%m;
    }
    ll tot = 0;
    for(int j = q;j <= i ; ++j) tot += dp[j];
    n -= (q-1);
    ans += (n/(i-q))*tot; 
    ll lft = (n%(i-q));
    for(int j = q;lft > 0 ; --lft , ++j)
      ans += dp[j];
    cout << ans << endl;
  }
}
