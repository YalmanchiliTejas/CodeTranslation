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

template<typename T>
class CumulativeSum{
public:
  Int n;
  vector<T> sum;
  vector<T> A;
  Int added;
  CumulativeSum():n(-1),added(0){}
  CumulativeSum(Int n):n(n), sum(n+1), A(n+1),added(0){}
  CumulativeSum(const vector<T> &B):n(B.size()), sum(n+1), A(n+1),added(0){
    for(Int i=1;i<=n;i++) sum[i] = sum[i-1] + B[i-1];
  }

  void apply(){
    for(Int i=1;i<=n;i++) A[i] = A[i] + A[i-1];
    for(Int i=1;i<=n;i++) A[i] = A[i] + A[i-1];
    for(Int i=1;i<=n;i++) sum[i] = sum[i] + A[i-1];
    added = 0; A.clear(); A.resize(n+1);
  }

  //[l, r)にxを加算
  void add(Int l, Int r, T x){
    added = 1;
    assert(l <= r && 0 <= l && r <= n);
    A[l] = A[l] + x;
    A[r] = A[r] - x;
  }

  //[l, r)の和を得る
  T get(Int l,Int r){
    assert(l<=r && 0<=l && r<=n);
    if(added) apply();
    return sum[r] - sum[l];
  }
};


vector<vector<P> > getAB(Int N){
  vector<vector<P> > res(N);
  for(Int x=1;x<N;x++){ //x = A - B
    Int B = N % x == 0? x:N % x;
    Int A = B + x;
    assert((N - A)%x == 0);
    assert((N - B)%x == 0);
    while(A <= N && B <= N){
      res[x].push_back(P(A, B));
      A += x, B += x;
    }
  }
  return res;
}

Int N;
vector<Int> s;
Int calcL(Int x, Int l, Int r){
  static CumulativeSum<Int> sum;
  static Int px = -1;
  if(px != x){
    px = x;
    sum = CumulativeSum<Int>(N/x + 1);
    for(Int i=0;i<N;i+=x) sum.add(i/x, i/x+1, s[i]);
  }
  return sum.get(l, r);
}

Int calcR(Int x,Int l, Int r){
  static CumulativeSum<Int> sum;
  static Int px = -1;
    if(px != x){
    px = x;
    sum = CumulativeSum<Int>(N/x + 1);
    for(Int i=0;i<N;i+=x) sum.add(i/x, i/x+1, s[N - 1 - i]);
  }
    return sum.get(l, r);
}

Int calc(Int A, Int B){
  Int x = A - B;
  if(!(((N-1) % x != 0) || ((N-1) % x == 0 && A * 2 > N-1))) return -INF;
  if(A == N-1) return s[N-1];
  Int a = calcL(x, 0, (N-1)/x - A/x + 1);
  Int b = calcR(x, 0, (N-1)/x - A/x + 1);
  return a + b;
}

Int calc2(Int A,Int B){
  Int x = 0;
  Int res = 0;
  set<Int> used;
  while(1){
    x = x + A;
    res += s[x];
    if(x == N - 1) return res;
    assert(x >= 0 && x < N);
    if(used.count(x)) return -INF;
    used.insert(x);
    
    x = x - B;
    res += s[x];
    if(x == N - 1) return res;
    assert(x >= 0 && x < N);
    if(used.count(x)) return -INF;
    used.insert(x);
  }
}

signed main(){
  srand((unsigned)time(NULL));
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  cin>>N;
  s.resize(N);
  cin>>s;

  Int ans = -INF;
  auto AB = getAB(N - 1);
  
  for(Int x=0;x<N-1;x++)
    for(auto p:AB[x]){
      Int A, B; tie(A, B) = p;
      Int score = calc(A, B);
      //pr(score, calc2(A, B));
      //assert(score == calc2(A, B));
      Max(ans, score);
    }

  cout<<ans<<endl;
  
  return 0;
}
