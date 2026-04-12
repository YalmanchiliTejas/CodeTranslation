#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <time.h>
#include <queue>
#include <string.h>
#define sf scanf
#define pf printf
#define lf double
#define ll long long
#define p123 printf("123\n");
#define pn printf("\n");
#define pk printf(" ");
#define p(n) printf("%d",n);
#define pln(n) printf("%d\n",n);
#define s(n) scanf("%d",&n);
#define ss(n) scanf("%s",n);
#define ps(n) printf("%s",n);
#define sld(n) scanf("%lld",&n);
#define pld(n) printf("%lld",n);
#define slf(n) scanf("%lf",&n);
#define plf(n) printf("%lf",n);
#define sc(n) scanf("%c",&n);
#define pc(n) printf("%c",n);
#define gc getchar();
#define re(n,a) memset(n,a,sizeof(n));
#define len(a) strlen(a)
#define LL long long
#define eps 1e-6
using namespace std;

ll length[100];
ll sum0[100];
ll sum = 0;
ll f(ll n,ll x0){
    if(n == 1){
        if(x0 == 1){
            return 0;
        }else if(x0 == 2){
            return 1;
        }else if(x0 == 3){
            return 2;
        }else if(x0 == 4){
            return 3;
        }else if(x0 == 5){
            return 3;
        }
    }
    if(x0 == 1){
        return 0;
    }else if(x0 == length[n]){
        return sum0[n];
    }if(x0 == ((length[n]+1)>>1)){
        return sum0[n-1]+1;
    }else if(x0 < ((length[n]+1)>>1)){
        return f(n-1,x0-1);
    }else{
        return f(n-1,(x0-length[n-1]-2))+sum0[n-1]+1;
    }
}


int main() {
    length[0] = 1;
    sum0[0] = 1;
    for(ll i = 1; i <= 50; i ++){
        length[i] = (length[i-1] *2 ) + 3;
        sum0[i] = sum0[i-1]*2+1;
    }
    //pld(sum0[50]); pn
    ll n,x;
    sld(n) sld(x);
    pld(f(n,x)); pn
    return 0;
}
//10 11 12 14 15
