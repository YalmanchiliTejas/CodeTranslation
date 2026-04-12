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
#define endl "\n"
#define all(v) (v).begin(),(v).end()
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef vector<pii> vpii;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mp make_pair


const int mod = 1e9+7;

inline int add(int a,int b){a+=b;if(a>=mod)a-=mod; return a;} 
inline int sub(int a,int b){a-=b;if(a<0) a += mod; return a;}
inline int mul(int a, int b){ return a*1ll*b%mod;}
inline int power(int x, ll y){
  int res = 1;
  while(y){
    if(y&1) res = mul(res , x);
    x = mul(x,x);
    y >>= 1;
  }
  return res;
}
const int N  = 2e5 + 100;
int A[N];

int main(){
  fio; cout<<fixed<<setprecision(25);	
  int ans = 0;
  int sm = 0;
  int n ; cin >> n;
  for(int i =1;i <= n ; ++i){
    cin >> A[i];
    sm = add(sm , A[i]);
  }
  for(int i = 1; i <= n;++i){
    ans = add(ans , mul(A[i], sub(sm , A[i])));
  }
  ans = mul(ans , power(2 , mod-2));
  
  cout << ans << endl;
  return 0;
}

