#include <bits/stdc++.h>
using namespace std;

#define NDEBUG
#ifdef DEBUG
#include "../cout11.h"
#undef NDEBUG
#endif
#include <cassert>

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
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long double> vD;

#define sz(a)  int((a).size())
#define pb  push_back
#define FOR(var,from,to) for(int var=(from);var<=(to);++var)
#define rep(var,n)  for(int var=0;var<(n);++var)
#define rep1(var,n)  for(int var=1;var<=(n);++var)
#define repC2(vari,varj,n)  for(int vari=0;vari<(n)-1;++vari)for(int varj=vari+1;varj<(n);++varj)
#define ALL(c)  (c).begin(),(c).end()
#define RALL(c)  (c).rbegin(),(c).rend()
#define tr(i,c)  for(auto i=(c).begin(); i!=(c).end(); ++i)
#define found(s,e)  ((s).find(e)!=(s).end())
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define mid(x,y) ((x)+((y)-(x))/2)
#define IN(x,a,b) ((a)<=(x)&&(x)<=(b))
#define cons make_pair


ll gcd(ll a, ll b) { while(a) swap(a, b%=a); return b; }

const ll MOD=1000000007LL;

ll ADD(ll x, ll y) { return (x+y) % MOD; }
ll SUB(ll x, ll y) { return (x-y+MOD) % MOD; }
ll MUL(ll x, ll y) { return x*y % MOD; }
ll POW(ll x, ll e) { ll v=1; for(; e; x=MUL(x,x), e>>=1) if (e&1) v = MUL(v,x); return v; }
ll DIV(ll x, ll y) { /*assert(y%MOD!=0);*/ return MUL(x, POW(y, MOD-2)); }

ll c[1001][1001];//
ll fact[1001];
ll _f[1001][1001];

void _prepare(int N) {
    c[0][0] = 1;
    c[1][0] = c[1][1] = 1;
    for (int n=2; n<=N; ++n) {
        c[n][0] = c[n][n] = 1;
        for (int j=1; j<n; ++j) {
            c[n][j] = ADD(c[n-1][j-1], c[n-1][j]);
        }
    }

    fact[0] = fact[1] = 1;
    for (int i=2; i<=1000; ++i) fact[i] = MUL(fact[i-1], i);

    rep(i,1001) rep(j,1001) _f[i][j] = -1;
}

//

int N,A,B,C,D;

void solve(){
    vector<ll> x(N+1, 0);
    x[0] = 1LL;
    for (int u=A; u<=B; ++u) {
        vector<ll> x2 = x;
        for (int b=0; b<N; ++b) { // base
            ll cx = 1;
            for (int k=1; k<=D; ++k) {
                if (b+u*k > N) break;
                cx = DIV(MUL(cx, c[b+u*k][u]), k);
                if (k < C) continue;
                x2[b+u*k] = ADD(x2[b+u*k], MUL(x[b], cx));
            }
        }
        x = x2;
#ifdef DEBUG
        cerr << x << endl;
#endif
    }
    cout << x[N] << endl;
}

int main() {
    _prepare(1000);

    cin >> N>>A>>B>>C>>D;
    solve();
    return 0;
}
