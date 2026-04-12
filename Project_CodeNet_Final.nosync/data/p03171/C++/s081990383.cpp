#include <bits/stdc++.h>
using namespace std;

#define NDEBUG
#ifdef DEBUG
#include "../cout11.h"
#undef NDEBUG
#endif
#include <cassert>

#ifdef DEBUG
#define debug(fmt, ...) fprintf(stderr, fmt, __VA_ARGS__)
#else
#define debug(fmt, ...)
#endif

typedef long long ll;
typedef long double Double;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<ll,ll> llll;
typedef pair<double,double> dd;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<llll> vllll;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long double> vD;

#define sz(a)  int((a).size())
#define pb  push_back
#define eb  emplace_back
#define FOR(var,from,to) for(int var=(from);var<=(to);++var)
#define rep(var,n)  for(int var=0;var<(n);++var)
#define rep1(var,n)  for(int var=1;var<=(n);++var)
#define repC2(vari,varj,n)  for(int vari=0;vari<(n)-1;++vari)for(int varj=vari+1;varj<(n);++varj)
#define repC3(vari,varj,vark,n)  for(int vari=0;vari<(n)-2;++vari)for(int varj=vari+1;varj<(n)-1;++varj)for(int vark=varj+1;vark<(n);++vark)
#define ALL(c)  (c).begin(),(c).end()
#define RALL(c)  (c).rbegin(),(c).rend()
#define tr(i,c)  for(auto i=(c).begin(); i!=(c).end(); ++i)
#define found(s,e)  ((s).find(e)!=(s).end())
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define mid(x,y) ((x)+((y)-(x))/2)
#define IN(x,a,b) ((a)<=(x)&&(x)<=(b))
#define cons make_pair

template<class T> inline void amin(T & a, T const & b) { a = min(a, b); }
template<class T> inline void amax(T & a, T const & b) { a = max(a, b); }
template<typename X, typename T> auto vectors(X x, T a) { return vector<T>(x, a); }
template<typename X, typename Y, typename Z, typename... Zs> auto vectors(X x, Y y, Z z, Zs... zs) { auto cont = vectors(y, z, zs...); return vector<decltype(cont)>(x, cont); }


int N;
ll dp[3001][3001];

int a[3001];

ll taro(int lo, int hi);
ll jiro(int lo, int hi);

ll taro(int lo, int hi) {
    if (lo == hi) return 0;
    if (lo+1 == hi) return a[lo];
    if (dp[lo][hi] != LLONG_MIN) return dp[lo][hi];
    // lo+2 <= hi
    ll left = a[lo] + jiro(lo+1, hi);
    ll right = jiro(lo, hi-1) + a[hi-1];
    return dp[lo][hi] = max(left, right);
}
ll jiro(int lo, int hi) {
    if (lo == hi) return 0;
    if (lo+1 == hi) return -a[lo];
    if (dp[lo][hi] != LLONG_MIN) return dp[lo][hi];

    ll left = -a[lo] + taro(lo+1, hi);
    ll right = taro(lo, hi-1) + -a[hi-1];
    return dp[lo][hi] = min(left, right);
}

ll solve(){
    rep(i,3001)rep(j,3001) dp[i][j] = LLONG_MIN;
    // mset(dp, -1);
    // rep(i,N+1) dp[i][i] = 0;
    return taro(0,N);
}

int main() {
    scanf("%d", &N);
    rep(i,N) scanf("%d", &a[i]);
    cout << solve() << endl;
    return 0;
}
