#include<bits/stdc++.h>
using namespace std;

// template {{{  0 
// using {{{ 1
using ll = long long int;
using llu = long long unsigned int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<pii>;
using vll = vector<pll>;
// }}} 1
// definition {{{ 1
// scaning {{{ 2
#define Scd(x) scanf("%d", &x)
#define Scd2(x,y) scanf("%d%d", &x, &y)
#define Scd3(x,y,z) scanf("%d%d%d", &x, &y, &z)
#define Scll(x) scanf("%lld", &x)
#define Scll2(x,y) scanf("%lld%lld", &x, &y)
#define Scll3(x,y,z) scanf("%lld%lld%lld", &x, &y, &z)
#define Scc(c) scanf("%c", &c);
#define Scs(s) scanf("%s", s);
#define Scstr(s) scanf("%s", &s);
// }}} 2
// constants {{{ 2
#define EPS (1e-7)
#define INF (2e9)
#define PI (acos(-1))
// }}} 2
// systems {{{ 2
#define Repe(x,y,z) for(ll x = z; x < y; x++)
#define Rep(x,y) Repe(x,y,0)
#define RRepe(x,y,z) for(ll x = y-z-1; x >= 0; x--)
#define RRep(x,y) RRepe(x,y,0)
// }}} 2
// output {{{ 2
#define YesNo(a) (a)?printf("Yes\n"):printf("No\n")
#define YESNO(a) (a)?printf("YES\n"):printf("NO\n")
// }}} 2
// }}} 1
// input {{{ 1
// }}} 1
// }}} 0

int main() {

    int N;
    Scd(N);

    vi a(N);
    Rep(i,N) Scd(a[i]);

    const ll LINF =  1e15;
    const ll NINF = -1e15;

    vector<vl> dpv(N+1,vl(N+1,NINF));
    function<ll(int,int)> dp = [&]( int l , int r ){
        if( l+r == N ) return dpv[l][r] = 0LL;
        if( dpv[l][r] != NINF ) return dpv[l][r];
        ll tmp;
        bool jiro = (l+r)%2;
        if( jiro ){
            tmp = LINF;
            tmp = min( dp(l+1,r)-a[  l  ], tmp );
            tmp = min( dp(l,r+1)-a[N-r-1], tmp );
        } else {
            tmp = NINF;
            tmp = max( dp(l+1,r)+a[  l  ], tmp );
            tmp = max( dp(l,r+1)+a[N-r-1], tmp );
        }
        return dpv[l][r] = tmp;
    };

    printf ("%lld\n", dp(0,0) );


    return 0;
}

