#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// template {{{  0 
// using {{{ 1
using ll = long long int;
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

    vl a(N+1);
    Rep(i,N) Scll(a[i]);

    ll dp[202020][4] = {};
    Repe(i,N,1){
        fill(dp[i],dp[i]+3,-1e18);
    }
    if( N%2==0 ){
        Rep(i,N/2){
            dp[i+1][0] = max( dp[i+1][0], dp[i][0] + a[i*2]  );
            dp[i+1][1] = max( dp[i+1][1], dp[i][0] + a[i*2+1]);
            dp[i+1][1] = max( dp[i+1][1], dp[i][1] + a[i*2+1]);
        }
    }else{
        Rep(i,N/2){
            dp[i+1][0] = max( dp[i+1][0], dp[i][0] + a[i*2]  );
            dp[i+1][1] = max( dp[i+1][1], dp[i][0] + a[i*2+1]);
            dp[i+1][2] = max( dp[i+1][2], dp[i][0] + a[i*2+2]);
            dp[i+1][1] = max( dp[i+1][1], dp[i][1] + a[i*2+1]);
            dp[i+1][2] = max( dp[i+1][2], dp[i][1] + a[i*2+2]);
            dp[i+1][2] = max( dp[i+1][2], dp[i][2] + a[i*2+2]);
        }
    }

    printf ("%lld\n", max(dp[N/2][0], max( dp[N/2][1], dp[N/2][2]) ) );

    return 0;
}

