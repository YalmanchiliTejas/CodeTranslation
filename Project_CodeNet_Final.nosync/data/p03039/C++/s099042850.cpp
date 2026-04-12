#include <bits/stdc++.h>
#define GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,NAME,...) NAME
#define pr(...) cerr<< GET_MACRO(__VA_ARGS__,pr8,pr7,pr6,pr5,pr4,pr3,pr2,pr1)(__VA_ARGS__) <<endl
#define pr1(a) (#a)<<"="<<(a)<<" "
#define pr2(a,b) pr1(a)<<pr1(b)
#define pr3(a,b,c) pr1(a)<<pr2(b,c)
#define pr4(a,b,c,d) pr1(a)<<pr3(b,c,d)
#define pr5(a,b,c,d,e) pr1(a)<<pr4(b,c,d,e)
#define pr6(a,b,c,d,e,f) pr1(a)<<pr5(b,c,d,e,f)
#define pr7(a,b,c,d,e,f,g) pr1(a)<<pr6(b,c,d,e,f,g)
#define pr8(a,b,c,d,e,f,g,h) pr1(a)<<pr7(b,c,d,e,f,g,h)
#define prArr(a) {cerr<<(#a)<<"={";int i=0;for(auto t:(a))cerr<<(i++?", ":"")<<t;cerr<<"}"<<endl;}
using namespace std;
using Int = long long;
using _int = int;
using ll = long long;
using Double = long double;
const Int INF = (1LL<<60)+1e9; // ~ 1.15 * 1e18
const Int mod = (1e9)+7;
const Double EPS = 1e-8;
const Double PI = 6.0 * asin((Double)0.5);
using P = pair<Int,Int>;
template<class T> T Max(T &a,T b){return a=max(a,b);}
template<class T> T Min(T &a,T b){return a=min(a,b);}
template<class T1, class T2> ostream& operator<<(ostream& o,pair<T1,T2> p){return o<<"("<<p.first<<","<<p.second<<")";}
template<class T1, class T2, class T3> ostream& operator<<(ostream& o,tuple<T1,T2,T3> t){
  return o<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<")";}
template<class T1, class T2> istream& operator>>(istream& i,pair<T1,T2> &p){return i>>p.first>>p.second;}
template<class T> ostream& operator<<(ostream& o,vector<T> a){Int i=0;for(T t:a)o<<(i++?" ":"")<<t;return o;}
template<class T> istream& operator>>(istream& i,vector<T> &a){for(T &t:a)i>>t;return i;}
//INSERT ABOVE HERE

class Combination{
public:
  typedef long long ll;
  ll N;
  ll mod;
  vector<ll> fac;
  vector<ll> finv;
  vector<ll> inv;
  
  
  Combination(ll N = 1e6,ll mod = 1e9 + 7): N(N), mod(mod), fac(N+1), finv(N+1), inv(N+1){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(Int i = 2; i <= N; i++){
      fac[i] = fac[i-1] * i % mod;
      inv[i] = mod - inv[mod%i] * (mod / i) % mod;
      finv[i] = finv[i-1] * inv[i] % mod;
    }
  }

  function<ll(ll,ll)> get = [&](ll n,ll r){
    if( n < r ) return 0LL;
    if( n < 0 || r < 0) return 0LL;
    return fac[n] * (finv[r] * finv[n-r] % mod) % mod;
  };
};
auto nCr = (new Combination())->get;

Int calc(Int N, Int M, Int K){
  Int sum = 0;
  for(Int l=1; l<N; l++){
    Int a = ((N - l) * M % mod) * M % mod;
    Int b = nCr(N * M - 2, K - 2);
    sum += (l * a % mod) * b % mod;
    sum %= mod;
  }
  return sum;
}

signed main(){
  srand((unsigned)time(NULL));
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  Int N, M, K;
  cin>>N>>M>>K;
  Int a = calc(N, M, K);
  Int b = calc(M, N, K);
  Int ans = (a + b) % mod;
  cout<<ans<<endl;
  return 0;
}
