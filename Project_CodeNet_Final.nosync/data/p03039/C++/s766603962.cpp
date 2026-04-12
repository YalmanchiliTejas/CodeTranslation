#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>

typedef long long ll;
typedef long double ld;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PRECISION std::cout << std::fixed << std::setprecision(20);
  
using namespace std;
 
const ll inf = 1e18;
const ll N = 2e5+1;
const ll bits = 20;
const ld pi = 3.14159265358979323846;
const ll mod = 1e9+7;
const ll p = 29;

ll fact[N];

ll power(ll x, ll n){
    ll res = 1;
    x%=mod;
    while(n){
        if(n&1) res = (res*x)%mod;
        x = (x*x)%mod;
        n>>=1;
    }
    return res;
}

ll ncr(ll n,ll r){
    ll num = fact[n];
    ll denom = (fact[r]*fact[n-r])%mod;
    return (num*power(denom,mod-2))%mod;  
}

ll sf(ll n){
    return ((n*(n+1))/2)%mod;
}

ll solve(ll n,ll m){
    ll ans = 0;
    for(ll x=0;x<n;x++){
        ll up = x;
        ll down = n-1-x;

        // cout<<x<<" "<<sf(x)<<" "<<sf(down)<<" "<<((sf(up)+sf(down))*m)<<"\n";
        if(up>down) swap(up,down);
        ans+=(((sf(up)+sf(down))%mod)*m)%mod;
        ans%=mod;
    }

    return (ans*m)%mod;
}

int main(){

    FASTIO;
    PRECISION; 

    fact[0] = 1;
    for(int i=1;i<N;i++){
        fact[i] = (i*fact[i-1])%mod;
    }

    ll n,m,k;
    cin>>n>>m>>k;

    ll cost = ncr(n*m-2,k-2);


    ll xans = solve(n,m);
    // return 0;
    ll yans = solve(m,n);

    ll ans = (xans+yans)%mod;
    
    ans = (ans*cost)%mod;
    ans*=power(2,mod-2);
    ans%=mod;
    cout<<ans<<"\n";

    
}
