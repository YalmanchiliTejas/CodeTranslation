#include <bits/stdc++.h>

#define _overload(_1,_2,_3,name,...) name
#define _rep(i,n) _range(i,0,n)
#define _range(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload(__VA_ARGS__,_range,_rep,)(__VA_ARGS__)

#define _rrep(i,n) _rrange(i,n,0)
#define _rrange(i,a,b) for(int i=int(a)-1;i>=int(b);--i)
#define rrep(...) _overload(__VA_ARGS__,_rrange,_rrep,)(__VA_ARGS__)

#define _all(arg) begin(arg),end(arg)
#define uniq(arg) sort(_all(arg)),(arg).erase(unique(_all(arg)),end(arg))
#define getidx(ary,key) lower_bound(_all(ary),key)-begin(ary)
#define clr(a,b) memset((a),(b),sizeof(a))
#define bit(n) (1LL<<(n))
#define popcount(n) (__builtin_popcountll(n))

using namespace std;

template<class T>bool chmax(T &a, const T &b) { return (a<b)?(a=b,1):0;}
template<class T>bool chmin(T &a, const T &b) { return (b<a)?(a=b,1):0;}

typedef long long ll;
typedef long double R;
const R EPS=1e-9L; // [-1000,1000]->EPS=1e-8 [-10000,10000]->EPS=1e-7
inline int sgn(const R& r){return(r > EPS)-(r < -EPS);}
inline R sq(R x){return sqrt(max(x,0.0L));}

const int dx[8]={1,0,-1,0,1,-1,-1,1};
const int dy[8]={0,1,0,-1,1,1,-1,-1};
vector<long long> a(51), p(51);

// Problem Specific Parameter:
long long f(long long N, long long X) {
  if(N==0LL) {
    if(X <= 0) return 0LL;
    else return 1LL;
  } else if(X <= 1 + a[N-1]) {
    return f(N-1, X-1);
  } else {
    return p[N-1] + 1 + f(N-1, X-2-a[N-1]);
  }
}

int main() {
  long long N, X; cin >> N >> X;
  a[0] = 1, p[0] = 1;
  for(int i = 1; i < N; ++i) {
    a[i] = a[i-1]*2 + 3;
    p[i] = p[i-1]*2 + 1;
  }

  cout << f(N, X) << endl;
  return 0;
}
