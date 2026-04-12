#include <bits/stdc++.h>  // include all standard C++ libraries

using namespace std;

// Loops
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define _rrep(i,n) rrepi(i,n,0)
#define rrepi(i,a,b) for(int i=int(a)-1;i>=int(b);--i)

#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define rrep(...) _overload3(__VA_ARGS__,rrepi,_rrep,)(__VA_ARGS__)
#define each(xi, x) for (auto&& xi : x)
// Note: we can use rep(i,N) or rep(i,from,to)


// typedef
using ll = long long;
template <class T> using vec = vector<T>;
using vi   = vector<int>;
using vvi  = vector<vi>;
using vvvi = vector<vvi>;
using pii  = pair<int, int>;


// Constants

// Shorter repr for frequently used terms
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fi first
#define Se second


// Algorithms
#define all(x) (x).begin(), (x).end()
#define uniq(v) v.erase( unique(all(v)), v.end() )
#define perm(c) sort(all(c));for(bool c##p=1;c##p;c##p=next_permutation(all(c)))

template<class T> pair<T, size_t> max(vector<T> &x){ auto it = max_element(all(x)); return mp(*it, it-x.begin()); }
template<class T> pair<T, size_t> min(vector<T> &x){ auto it = min_element(all(x)); return mp(*it, it-x.begin()); }

template<class T> inline bool chmax(T &maxval, const T &newval) { if (maxval<newval) { maxval=newval; return 1; } return 0; }
template<class T> inline bool chmin(T &minval, const T &newval) { if (minval<newval) { minval=newval; return 1; } return 0; }

// Utilities
// Grid world utilities
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
#define inside(H,W,y,x) 0<=(x) && (x)<(W) && 0<=(y) && (y)<(H)

inline int in() {int x; cin >> x; return x;} // read int from cin
inline  ll IN() {ll x; cin >> x; return x;}  // read ll from cin



// Debug
#ifdef LOCAL
  #include "dump.hpp"
  #define debug(x) cerr << #x << ": " << x << '\n'
#else
  #define dump(...)
  #define debug(x)
#endif

// Paste snippets here!!
string burger(int N, vector<string> &lb){
  if(N==0) { lb[N]="P"; return lb[N]; }
  if(lb[N]=="") lb[N] = string("B")+burger(N-1,lb)+"P"+burger(N-1,lb)+"B";
  return lb[N];
}
// 

ll myrank(int N, ll X, const vector<ll> &npaty, const vector<ll> &height){
  // count paty within level-N-burger[0,X)
  if(N==0) return 1;
  if(X==1) return 0;
  else if(1<X && X<1+height[N-1]) return myrank(N-1,X-1,npaty,height);
  else if(X==1+height[N-1]) return npaty[N-1];
  else if(X==2+height[N-1]) return npaty[N-1]+1;
  else if(2+height[N-1]<X && X<2+2*height[N-1]) return npaty[N-1]+1+myrank(N-1,X-height[N-1]-2,npaty,height);
  return npaty[N];
}

int main(){
  cin.tie(0); ios::sync_with_stdio(false);    // Magic for faster cin
  vector<string> lb(51);
  int N=in(); ll X=IN();
  dump(N,X);

  vector<ll> npaty(N+1);
  vector<ll> height(N+1);
  npaty[0] = 1;
  height[0] = 1;
  rep(i, 1, N+1){
    npaty[i] = 2*npaty[i-1]+1;
    height[i] = 2*height[i-1] + 3;
  }
  dump(npaty, height);
  
  cout << myrank(N,X,npaty,height) << endl;

  // string burg = burger(N,lb);
  // int r=0;
  // rep(i,X){
  //   r+=(burg[i]=='P');
  // }
  // cout << r << endl;

  // 4321098765432109
  // 2251799813685245
  return 0;
}
