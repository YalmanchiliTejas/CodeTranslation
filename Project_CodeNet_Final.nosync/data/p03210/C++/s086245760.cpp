#define _GLIBCXX_DEBUG
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <utility>
#include <vector>
using namespace std;
#define mp make_pair
#define pb push_back
#define FI first
#define SE second
#define FOR(i,a,b) for(int (i)=((int)a); (i)<((int)b); (i)++) // [a,b)
#define REP(i,N) FOR((i), 0, ((int)N)) // [0,N)
#define INF (1 << 30)
#define icin(x) int x; cin >> x
#define lcin(x) ll x; cin >> x
#define dcin(x) double x; cin >> x
#define scin(s) string s; cin >> s 
#define all(v) (v).begin(),(v).end()
#define vsz(v) ((int)(v).size())
#define vcin(v,N) vi v(N); REP(i,N) cin >> v[i] // 配列にも使用可能
#define vcinl(v,N) vl v(N); REP(i,N) cin >> v[i]
#define vmax(v) *max_element(all(v)) // 遅い？いつか書き直す
#define vmin(v) *min_element(all(v))
#define vidx(v,it) distance((v).begin(),(it))
#define vsum(v) accumulate(all(v),0)
#define vsumr(v,a,b) accumulate((v).begin()+(a),(v).begin()+(b),0) //[a,b)
#define vfnd(v,val) find(all(v),val) // itrを返す。存在しない場合v.end()を返す
#define vcnt(v,val) count(all(v),val)
#define vrep(v,it) for(auto it=(v).begin(); it != (v).end(); ++it)
#define IOS ios_base::sync_with_stdio(0); cin.tie(0) // IOS;で高速化

// デバッグ用
// dbg(...) printfと同様に使用可能 
// trc(var) (変数名)=(値)と表示
// stopif(val) 条件分が真の時に止まる
// vdbg(v) vの中身を表示
#ifdef LOCAL
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
    #define trc(var) cout << #var << "=" << var << endl;
    #define trc2(v) cout << #v << "={"; 
    #define stopif(val) assert( !(val) )
    #define vdbg(v) vector_debug(v)
#else
    #define dbg(...) 1
    #define trc(var) 1
    #define trc2(v) 1
    #define stopif(val) 1
    #define vdbg(v) 1
#endif

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector< vector<int> > vvi;
int gcd(int a, int b){if(a>b) swap(a,b); return a==0 ? b : gcd(b%a,a);}
ll gcd(ll a, ll b){if(a>b) swap(a,b); return a==0 ? b : gcd(b%a,a);}
template<typename C> inline void vector_debug(vector<C> v){trc2(v);ostream_iterator<C> o(cout,",");copy(all(v),o);cout<<"}"<<endl;}
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

// icin(x) ... int x; cin >> x;
// vcin(A,N),vcinl vi(vl) Aを宣言してcinで初期化

int main(){ IOS;
    icin(X);
    if(X==3 || X==5 || X==7)cout << "YES" <<endl;
    else cout << "NO" << endl;
    return 0;
}