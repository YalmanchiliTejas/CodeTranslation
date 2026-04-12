#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define LLINF 9223372036854775807
#define MOD ll(1e9+7)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cerr<<#x<<": "<<x<<endl



#define MAX_N 200005


ll factorial[MAX_N];
void make_factorial_tableMOD(){
    factorial[0] = 1;
    for(int i = 1; i < MAX_N; i++){
        factorial[i] = factorial[i-1]*i%MOD;
    }
}

ll bisection_powerMOD(ll x,ll y){
    if(y==0)        { return 1; }
    ll t = bisection_powerMOD(x*x%MOD,y/2);
    if(y%2==1)      { t = t*x%MOD; }
    return t;
}

ll nCrMOD(ll n, ll r){
    if(n<r || n<=0 || r<0){return 0;}
    ll a = factorial[n];
    ll b = a*bisection_powerMOD(factorial[r],(MOD-2))%MOD;
    ll c = b*bisection_powerMOD(factorial[n-r],MOD-2)%MOD;
    return c % MOD;
}

int main(){
    ll n, m, k;
    cin >> n >> m >> k;

    make_factorial_tableMOD();


    ll c = nCrMOD(n*m-2,k-2);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += i*(n-i)*m*m*c;
        ans %= MOD;

    }

    for(int i = 0; i < m; i++){
        ans += i*(m-i)*n*n*c;
        ans %= MOD;

    }

    cout << ans%MOD << endl;

    return 0;
}
