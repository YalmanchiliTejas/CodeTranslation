#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
#define REP(i, n) for(ll i=0; i<(ll)(n); i++)
#define REPD(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))

ll calc(ll n, ll x){
    if(n==0) return 1;
    ll b = (1LL<<(n+1))-3;
    ll p = (1LL<<n) - 1;
    if(x==1) return 0;
    if(x<=1+b) return calc(n-1, x-1);
    if(x==2+b)   return p+1;
    if(x<=2+2*b) return   p + 1 + calc(n-1, x-2-b);
    return 2*p+1;

}


int main(){
    ll n, x;   cin >> n >> x;

    cout << calc(n, x) << endl;
}