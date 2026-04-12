#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> vec;
typedef vector<vec> vec2;
typedef map<ll,ll> MPll;
typedef set<ll> setl;

const ll INF = 1ll << 60;
const ld EPS = 1e-10;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};

//for文
#define FOR(i,a,b) for(ll i = (ll)a;i < (ll)b;i++)
#define FORE(i,a,b) for(ll i = (ll) a;i <= (ll) b;i++ )
#define REP(i,size)  for(ll i =(ll)0;i<size;i++)
#define REPE(i,size)  for(ll i =(ll)0;i<=size;i++)
#define REPR(i,size)  for(ll i =(ll)size;i>=0;i--)
#define FOREACH(it, vec) for (auto it = vec.begin(); it != vec.end(); it++)

//ソート
#define ALL(vec) (vec).begin(),(vec).end()
#define SORT(vec) sort(ALL(vec))
#define SORTA(arr) sort(arr,arr + (sizeof(arr) / sizeof(ll)))
#define INVSORT(vec) sort((vec).rbegin(),(vec).rend())
#define REV(vec) reverse(ALL(vec))
#define REVA(arr) reverse(arr,arr + (sizeof(arr) / sizeof(ll)))
#define INVSORTA(arr) sort(arr,arr + (sizeof(arr) / sizeof(ll))),REVA(arr)

//最大値最小値
#define MAX(vec) *max_element(ALL(vec))
#define UNIQ(vec) SORT(vec);vec.erase(unique(ALL(vec)),vec.end())
#define MIN(vec) *min_element(ALL(vec))

//出力
#define printl(a) cout << a << "\n"
#define print(a) cout << a
#define OUT(a) printf("%lld\n",a)
#define OUTA(array) REP(i,sizeof(array)/sizeof(ll)) printf("%lld\n",array[i])
#define OUTV(vec) REP(i,vec.size()) printf("%lld\n",vec[i])
#define SP printf(" ")

//入力
#define IN(x) scanf("%lld",&x)
#define INV(vec) REP(i,vec.size()) scanf("%lld",&vec[i])
#define INA(array) REP(i,sizeof(array)/sizeof(ll)) scanf("%lld",array + i)
#define INS(x) cin >> x
#define INCH(x) scanf(" %c",&x)

//型
#define P pair
#define vp vector<P>
#define F first
#define S second

//その他
#define PB push_back
#define MP make_pair
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,-1,sizeof(a))
#define INFI(a) memset(a,INF,sizeof(a))
#define MEM(a,b) memset(a,(b),sizeof(a))

//関数
template<class T> inline void amax(T &a,const T &b) { if(a < b) a = b; }
template<class T> inline void amin(T &a, const T &b) { if(a > b) a = b; }
/*
struct structure{
    ll num1,num2,string s;
    bool operator<(const rest &another) const{
        return this->s < another.s;
    }
    structure(ll a,ll b,string s){
        this->num1 = a,this->num2=b,this->s=s;
    }
};a
*/
//特殊
//#define int ll
#define _CRT_SECURE_NO_WARNINGS



/*
template <typename T>
struct UnionFindTree{

    vector<T> par;

    UnionFindTree(T n) : par(n+1){
        for (int i = 1; i <= n; ++i) {
            par[i] = i;
        }
    }

    T root(T x){
        if(par[x] == x) return x;
        else  return par[x] = root(par[x]);
    }

    void unite(T x,T y){
        if(!same(x,y)) par[root(x)] = root(par[y]);
    }

    T same(T x,T y){
        return root(x) == root(y);
    }

};
*/

//#define DEBUG

#ifdef DEBUG
    #define debugl(x) cerr << #x << ":" << x<<"\n"
    #define debug(x)  cerr << x
    #define  debugV(V) REP(i,V.size()){cerr << i << ":" << V[i]<<endl;}
    #define  debugA(A) REP(i,sizeof(A)/sizeof(ll)){cerr << i << ":" << V[i]<<endl;}
#else
    #define debug(x)
    #define debugV(x)
    #define debugA(x)
    #define debugl(x)
#endif

#define ZERO(a) memset(a,0,sizeof(a))
#define ALL(vec) (vec).begin(),(vec).end()
#define SORT(vec) sort(ALL(vec))


signed main(){
    ll N;
    IN(N);
    ll takai = 0;
    ll h;
    ll ans = 0;

    for (int i = 0; i <N ; ++i) {
        IN(h);
        if(h >= takai){
            ans++;
            takai = h;
        }

    }

    OUT(ans);
}
