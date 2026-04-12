#include<bits/stdc++.h>
using namespace std;
typedef long long unsigned int ll;

// definition {{{ 1

// scaning {{{ 2
#define Scd(x) scanf("%d", &x)
#define Scd2(x,y) scanf("%d%d", &x, &y)
#define Scd3(x,y,z) scanf("%d%d%d", &x, &y, &z)

#define Scll(x) scanf("%llu", &x)
#define Scll2(x,y) scanf("%llu%llu", &x, &y)
#define Scll3(x,y,z) scanf("%llu%llu%llu", &x, &y, &z)

#define Scc(c) scanf("%c", &c);
#define Scs(s) scanf("%s", s);
#define Scstr(s) scanf("%s", &s);
// }}} 2

// constants {{{ 2
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
// }}} 2

// systems {{{ 2
#define Rep(x,y) for(int x = 0; x < y; x++)
#define Repe(x,y,z) for(int x = z; x < y; x++)
// }}} 2

// output {{{ 2
#define YesNo(a) (a)?printf("Yes\n"):printf("No\n");
// }}} 2

// }}} 1

ll base_ten[10004];

int main() {

    int d;
    char n[10023] = {};
    ll dp[100][2][2] = {{{}}};
    // [dでの変位][n%2桁目][最大？ 1で最大]
    ll mod = 1000000007;

    Scs(n);
    Scd(d);
    int l = strlen(n);
    base_ten[0] = 1;
    Rep(i,l) n[i]-='0';
    Rep(i,l) base_ten[i+1] = base_ten[i] * 1 % d;

    dp[0][0][1] = 1;
    Rep(li,l){
        Rep(di,d){
            Rep(fi,2){
                dp[di][(li+1)%2][fi] = 0;
            }
        }
        Rep(di,d){
            Rep(fi,2){
                int nn = fi ? n[li]+1 : 10;
                Rep(xi,nn){
                    int flag = fi && xi == n[li];
                    dp[(di+xi*base_ten[l-li-1])%d][(li+1)%2][flag] += dp[di][li%2][fi];
                    dp[(di+xi*base_ten[l-li-1])%d][(li+1)%2][flag] %= mod;
                }
            }
        }
    }

    printf ("%llu\n", (dp[0][l%2][0]+dp[0][l%2][1]+mod-1)%mod );



    return 0;
}

