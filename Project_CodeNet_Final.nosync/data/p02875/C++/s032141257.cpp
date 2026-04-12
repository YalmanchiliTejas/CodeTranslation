#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 0x3f3f3f3f
#define MOD 998244353
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 10000005
ll n;
ll dp[MN];
ll fac[MN];

void modInvs(int n){
    dp[0] = dp[1] = 1; 
    for (int i=2; i<=n; i++){
        dp[i]=dp[MOD % i]*(MOD - MOD / i) % MOD;
    }
}

ll modExp(ll b, ll ex){
    ll prod = 1;
    while(ex > 0){
        if(ex % 2 == 0){
            b = (b * b) % MOD;
            ex /= 2;
        } else{
            prod = (prod*b) % MOD;
            ex--;
        }
    }
    
    return prod;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    
    modInvs(n);

    ll sm = 0;
    ll p2 = 1;
    ll ch = 1;
    FOR(i, 0, n/2-1){
        sm += (p2*ch)%MOD;
        sm %= MOD;
        p2 = (p2*2)%MOD;
        ch = ((ch*(n-i))%MOD)*dp[i+1];
        ch %= MOD;
    }

    sm = (sm*2)%MOD;
    ll pw = modExp(3, n);
    cout << (pw-sm+MOD)%MOD << "\n";

    return 0;
}
