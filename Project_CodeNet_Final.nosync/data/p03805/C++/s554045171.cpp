#define _GLIBCXX_DEBUG
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define whlie while
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define inf 1001001001
#define mod 1000000007
#define FOR(i,a,b) for(int (i)=((int)a); (i)<((int)b); (i)++) // [a,b]
#define rep(i,N) FOR((i), 0, ((int)N)) // [0,N)
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define in(t,...) t __VA_ARGS__; _in(__VA_ARGS__)
#define ini(...) int __VA_ARGS__; _in(__VA_ARGS__)
#define inl(...) ll __VA_ARGS__; _in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; _in(__VA_ARGS__)
#define ind(...) double __VA_ARGS__; _in(__VA_ARGS__)
#define invi(...) vi __VA_ARGS__; vin(__VA_ARGS__)
#define invl(...) vl __VA_ARGS__; vin(__VA_ARGS__)
#define vrep(v,it) for(auto it=(v).begin(); it != (v).end(); ++it)
// デバッグ用
// dbg(...) printfと同様に使用可能 
// trc(var) (変数名)=(値)と表示
// stopif(val) 条件分が真の時に止まる
// vdbg(v) vの中身を表示

#ifdef LOCAL
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
    #define trc(var) cout << #var << "=" << var << endl
    #define stopif(val) assert( !(val) )
    #define vdbg(v,...) cout << #v << "={"; vector_debug(v , ##__VA_ARGS__)
#else
    #define dbg(...) 1
    #define trc(...) 1
    #define stopif(...) 1
    #define vdbg(...) 1
#endif

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector< vector<int> > vvi;
int gcd(int a, int b){if(a>b) swap(a,b); return a==0 ? b : gcd(b%a,a);} ll gcd(ll a, ll b){if(a>b) swap(a,b); return a==0 ? b : gcd(b%a,a);}
template<typename T, typename U> inline bool amin(T &x, U y) { return (y < x) ? (x = y, true) : false; }
template<typename T, typename U> inline bool amax(T &x, U y) { return (x < y) ? (x = y, true) : false; }
template<typename C> inline void _cin(C &c){cin >> c;} template<typename T,typename U> inline void _cin(pair<T,U> &p){cin >> p.fi; cin >> p.se;}
template<typename C> inline void vin(vector<C> &v,int N=-1){if(sz(v) != 0){int M=(N == -1) ? sz(v) : N; rep(i,M) _cin(v[i]);}else{C c;rep(i,N) v.pb((_cin(c),c));}} template<typename C> inline void vin(C v[],int N){rep(i,N) _cin(v[i]);}
template<typename C> inline void vout(const vector<C> &v,int N=-1){int M=(N == -1) ? sz(v) : N; rep(i,M) cout<<( (i)?" ":"" )<<v[i]; cout<<endl; } template<typename C> inline void vout(C v[],int N){rep(i,N) cout<<( (i)?" ":"" )<<v[i]; cout<<endl; }
template<typename C> inline void vector_debug(const vector<C> &v){ostream_iterator<C> o(cout,",");copy(all(v),o);cout<<"}"<<endl;} template<typename C> inline void vector_debug(C v[], int N){rep(i,N) cout<<((i)?",":"")<<*(v+i); cout<<"}"<<endl;}
template<typename C> inline C vmax(const vector<C> &v){C n=v[0]; rep(i,sz(v)) amax(n,v[i]); return n;} template<typename C> inline C vmax(C v[], int N){C n=v[0]; rep( i , N ) amax(n,v[i]); return n;}
template<typename C> inline C vmin(const vector<C> &v){C n=v[0]; rep(i,sz(v)) amin(n,v[i]); return n;} template<typename C> inline C vmin(C v[], int N){C n=v[0]; rep( i , N ) amin(n,v[i]); return n;}
template<typename C> inline C vsum(const vector<C> &v){C n=0; rep(i,sz(v)) n+=v[i]; return n;} template<typename C> inline C vsum(C v[], int N){C n=0; rep( i , N ) n+=v[i]; return n;}
void _in(){} template <typename T,class... U> void _in(T &t,U &...u){ _cin(t); _in(u...);}
void out(){cout << endl;} template <typename T,class... U> void out(T const &t,U ...u){ cout << t; if(sizeof...(u)) cout << ' '; out(u...);}
const int dx[]={1,0,-1,0}; const int dy[]={0,1,0,-1};
//const int dx[]={1,1,1,0,-1,-1,-1,0}; const int dy[]={1,0,-1,-1,-1,0,1,1};

// in(int,A,B,C) int A,B,C; cin >> A >> B >> C;
// out(A,B,C) cout << A << ' ' <<  B << ' ' << C;
// amax(x,y) bool関数　x<yの時にxにyを代入してtrueを返す
// vin(v,N) ベクトル/配列にcinする vout(v,N) ベクトル/配列をcoutする(ベクトルはNを省略可能)

int A[10][10];

int main(){
    ini(N,M);
    rep(i,10) rep(j,10) A[i][j]=0;
    rep(i,M){
        ini(a,b);
        A[a-1][b-1]=1; A[b-1][a-1]=1;
    }
    vi v;
    FOR(i,1,N) v.pb(i);
    int cnt = 0;
    do{
        int cur = 0,flg = 1;
        rep(i,N-1){
            if(A[cur][v[i]] == 0)flg = 0;
            cur = v[i];
        }
        cnt += flg;
        vdbg(v); trc(flg);
    }while(next_permutation(all(v)));
    out(cnt);
}