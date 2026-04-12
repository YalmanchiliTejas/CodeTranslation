#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <time.h>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <stack>
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
using namespace std;
//https://codeforces.com/contest/1213/problems
//https://codeforces.com/contest/1213/submit
ll a[100];
    ll n;
bool is(){

    for(ll i = 0; i < 50; i ++){
        if(a[i] >= n){
            return false;
        }
    }
    return true;
}
int main(){
    sld(n)
    for(ll i = 0; i < n; i ++){
        sld(a[i])
    }
    ll count0 = 0ll;
    while(1){
        if(is()){
            break;
        }
        ll maxi = 0ll;
        for(ll i = 0; i < n; i ++){
            if(a[maxi] < a[i]){
                maxi = i;
            }
        }
        ll x = a[maxi]/n;
        //ll y = a[maxi]%n;
        //pld(x) pn
        count0 += x;
        for(ll i = 0; i < n; i ++){
            //pld(a[i]) pk
            if(maxi != i){
                a[i] += x;
            }else{
                a[i] -= n*x;
            }
        }
        //pn
    }
    /*for(ll i = 0; i < n; i ++){
            pld(a[i]) pk

        }*/
        //pn
    pld(count0) pn





    return 0;
}
