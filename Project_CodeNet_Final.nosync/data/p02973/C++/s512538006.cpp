#include <bits/stdc++.h>
using namespace std;
/// Typedef
typedef long long           ll;
typedef vector<int>         vi;
typedef pair<int,int>       pii;

#define pb                  push_back
#define ppb                 pop_back
#define MP                  make_pair
#define ff                  first
#define ss                  second
#define sf                  scanf
#define pf                  printf
#define SQR(x)              ((x)*(x))
#define loop(i, y)          for(int i=0; i<int(y); i++)
#define FOR(i, x, y)        for(int i=int(x); i<int(y); i++)
#define ROF(i, x, y)        for(int i=int(x); i>=int(y); i--)
#define all(c)              c.begin(), c.end()
#define sz(c)               int(c.size())
#define clr(x, y)           memset(x, y, sizeof(x))
#define si(x)               scanf("%d", &x)
#define sii(x, y)           scanf("%d %d", &x, &y)
#define siii(x, y, z)       scanf("%d %d %d", &x, &y, &z)
#define sl(x)               scanf("%lld", &x)
#define sll(x, y)           scanf("%lld %lld", &x, &y)
#define slll(x, y, z)       scanf("%lld %lld %lld", &x, &y, &z)

#ifdef VAMP
     #define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template < typename Arg1 >
    void __f(const char* name, Arg1&& arg1){
        cout << name << " = " << arg1 << std::endl;
    }
    template < typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names+1, ',');
        cout.write(names, comma - names) << " = " << arg1 <<" | ";
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif
///******************************************START******************************************

/// Constants
#define MAX                 200005
#define MOD                 1000000007
#define eps                 1e-9
#define INF                 0x3f3f3f3f3f3f3f3f // 4,557,430,888,798,830,399
#define inf                 0x3f3f3f3f // 1,061,109,567
#define PI                  acos(-1.0)  // 3.1415926535897932
#define VT                  int

int n;
pair<int, int> ar[MAX];
map<int, int> mp;

int solve(){
    vector<pii> v;
    FOR(i, 0, n){
        auto pos = lower_bound(all(v), ar[i]);
        if(pos == v.end()) v.pb(ar[i]);
        else v[pos - v.begin()] = ar[i];
    }
    return sz(v);
}

int main(){
    #ifdef VAMP
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    si(n);
    FOR(i, 0, n){
        int x; si(x);
        ar[i] = {x, mp[x]++};
    }
    reverse(ar, ar+n);
    FOR(i, 0, n){
        ar[i] = {ar[i].ff, mp[ar[i].ff] - ar[i].ss};
    }
    printf("%d\n", solve());

    #ifdef VAMP
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif
    return 0;
}