#include<bits/stdc++.h>
using namespace std;
typedef long long unsigned int ll;

// PowMod( base, index, modulo) return base ** index % modulo {{{
// PowMod = base ** index % mod ( natural numbers )
long long unsigned int Pow( long long unsigned int base, long long unsigned int index ){
    if( index == 0 ) return 1;
    // O( log(index) )
    if( index % 2 ){
        return base * Pow(base, index - 1);
    }else{
        long long unsigned int Phalf = index / 2;
        long long unsigned int half = Pow(base, Phalf);
        return half * half;
    }
}
// }}}

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

ll ans = 0;
ll p[54] = {};
ll bp[54] = {};
int n;
ll x;

void answer( ll l , int lv ){
    if( l <=  0 ) return;
    if( lv <= 0 ) {ans++; return;}
    //printf ("%llu\n", l);
    if( l <= bp[lv] / 2 ){
        answer( l-1 , lv-1 );
    }else{
        ans += p[lv];
        ans++;
        l -= bp[lv-1];
        l--;
        l--;
        answer( l , lv-1 );
    }
}

int main() {

    Scd(n);
    Scll(x);

    ll leng = Pow(2,n+2) - 3;

    bp[0] = 1;

    Repe(i,n+1,1){
        p[i] = p[i-1] * 2 + 1;
        bp[i] = bp[i-1] * 2 + 3;
    }

    answer(x,n);
    printf ("%llu\n", ans);


    return 0;
}

