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

int main() {

    int n;
    int a[200004];
    int ans[200003];

    Scd(n);

    Rep(i,n){
        Scd(a[i]);
    }

    int head = 0;
    int butt = n-1;
    Rep(i,n){
        if( i % 2 == 0 ){
            ans[head++] = a[n-i-1];
        }else{
            ans[butt--] = a[n-i-1];
        }
    }

    Rep(i,n){
        printf( "%d",ans[i] );
        if( i != n-1 ) printf (" ");
        else printf ("\n");
    }


    return 0;
}

