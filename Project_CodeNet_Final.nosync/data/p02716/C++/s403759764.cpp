// template version 1.15
using namespace std;
#include <bits/stdc++.h>

// varibable settings
#define int long long
const int INF=1e18;

// define basic macro {{{
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define _rrep(i,n) rrepi(i,0,n)
#define rrepi(i,a,b) for(int i=(int)((b)-1);i>=(int)(a);--i)
#define rrep(...) _overload3(__VA_ARGS__,rrepi,_rrep,)(__VA_ARGS__)
#define each(i,a) for (auto&& i : a)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define mt(a, b, c) make_tuple(a, b, c)
#define ub upper_bound
#define lb lower_bound
#define posl(A, x) (lower_bound(all(A), x)-A.begin())
#define posu(A, x) (upper_bound(all(A),x)-A.begin())
template<class T> inline void chmax(T &a, const T &b) { if((a) < (b)) (a) = (b); }
template<class T> inline void chmin(T &a, const T &b) { if((a) > (b)) (a) = (b); }

#define divceil(a,b) ((a)+(b)-1)/(b)
#define is_in(x, a, b) ((a)<=(x) && (x)<(b))
#define uni(x) sort(all(x));x.erase(unique(all(x)),x.end())
#define slice(l, r) substr(l, r-l)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;
typedef pair<int,int> pii;
typedef tuple<int,int,int> iii;

template<typename T> using PQ = priority_queue<T, vector<T>, greater<T>>;
struct Fast { Fast(){ std::cin.tie(0); ios::sync_with_stdio(false); } } fast;

#if defined(PCM) || defined(LOCAL)
    #include "lib/dump.hpp"
#else
    #define dump(...) 42
    #define dump_1d(...) 42
    #define dump_2d(...) 42
    #define cerrendl 42
#endif
//}}}
int solve(){
    int n;cin>>n;
    vector<int> a(n+1);
    rep(i, 1, n+1) { cin>>a[i]; }
    dump(a);

    vector<map<int, int>> dp0(n+1);
    vector<map<int, int>> dp1(n+1);
    rep(j, -5, 10){
        int v = - 3 + j;
        dp0[0][v] = -INF;
        dp1[0][v] = -INF;
    }

    dp0[0][0] = 0;

    rep(i, 1, n+1){
        rep(j, -5, 10){
            int v = i/2 - 3 + j;
            dp0[i][v] = -INF;
            dp1[i][v] = -INF;
        }
        rep(j, 0, 5){
            int v = i/2 - 3 + j;

            // toranai
            chmax(dp0[i][v], dp0[i-1][v]);
            chmax(dp0[i][v], dp1[i-1][v]);

            // toru
            chmax(dp1[i][v], dp0[i-1][v-1]+a[i]);
        }
    }
    rep(i, n+1){
        dump(dp0[i]);
        dump(dp1[i]);
    }
    cout << max(dp0[n][n/2], dp1[n][n/2]) << endl;

    return 0;
}

signed main() { //{{{
#ifdef INPUT_FROM_FILE
    std::ifstream in(infile);
    std::cin.rdbuf(in.rdbuf());
#endif
    solve();
    return 0;
} //}}}
