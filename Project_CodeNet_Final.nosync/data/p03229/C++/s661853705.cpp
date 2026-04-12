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
    int a[100003] = {};

    Scd(n);
    Rep(i,n){
        Scd(a[i]);
    }

    sort(a,a+n);

    int l = 0, r = n-1;
    ll ans1 = 0, ans2 = 0;
    int k[100003] = {};
    int to = 0;
    if( n % 2 ){
        k[0] = a[n/2];
        to++;
        while( to < n ){
            k[to++] = a[l++];
            if( to == n ) break;
            k[to++] = a[r--];
        }
        Repe(i,n,0){
            if( i == 0 ) continue;
            ans1 += abs(k[i]-k[i-1]);
        }
        to = 1;
        l = 0;
        r = n-1;
        while( to < n ){
            k[to++] = a[r--];
            if( to == n ) break;
            k[to++] = a[l++];
        }
        Repe(i,n,0){
            if( i == 0 ) continue;
            ans2 += abs(k[i]-k[i-1]);
        }
    }else{
        k[0] = a[n/2];
        k[n-1] = a[n/2-1];
        to = 1;
        while( to < n-1 ){
            k[to++] = a[l++];
            if( to == n-1 ) break;
            k[to++] = a[r--];
        }
        Repe(i,n,0){
            if( i == 0 ) continue;
            ans1 += abs(k[i]-k[i-1]);
        }
        to = 1;
        l = 0;
        r = n-1;
        while( to < n-1 ){
            k[to++] = a[r--];
            if( to == n-1 ) break;
            k[to++] = a[l++];
        }
        Repe(i,n,0){
            if( i == 0 ) continue;
            ans2 += abs(k[i]-k[i-1]);
        }
    }

    printf ("%llu\n", max(ans1, ans2) );

    return 0;
}

