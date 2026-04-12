//satyaki3794
#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define MOD (1000000007LL)
#define LEFT(n) (2*(n))
#define RIGHT(n) (2*(n)+1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

ll pwr(ll base, ll p, ll mod = MOD){
ll ans = 1;while(p){if(p&1)ans=(ans*base)%mod;base=(base*base)%mod;p/=2;}return ans;
}


ll gcd(ll a, ll b){
    if(b == 0)  return a;
    return gcd(b, a%b);
}


int n, A, B, c, d;
ll fac[1002], DP[1005][1005], invFac[1003], ncr[1003][1004], powers[1002][1002];

ll dp(int rem, int g){

    if(rem == 0)    return 1;
    if(g == B+1)    return 0;
    ll &ans = DP[rem][g];
    if(ans != -1)   return ans;

    ans = dp(rem, g+1);
    for(int i=c*g;i<=rem&&i<=d*g;i+=g){
    
// if(!((rem==7&&g==2&&i==4) || (rem==3&&g==3&&i==3)))    continue;

        ll temp = ncr[rem][i];
        temp = (temp * fac[i]) % MOD;
        temp = (temp * invFac[i/g]) % MOD;
        temp = (temp * powers[g][i/g]) % MOD;

        if(i >= c*g)    ans = (ans + temp*dp(rem-i, g+1)) % MOD;
    }

// cout<<"dp "<<rem<<" "<<g<<" returns "<<ans<<endl;
    return ans;
}



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fac[0] = invFac[0] = 1;
    for(int i=1;i<=1001;i++){
        fac[i] = (i * fac[i-1]) % MOD;
        invFac[i] = pwr(fac[i], MOD-2);
    }

    for(int i=1;i<=1001;i++){
        powers[i][0] = 1;
        for(int j=1;j<=1001;j++)
            powers[i][j] = (powers[i][j-1] * invFac[i]) % MOD;
    }

    ncr[0][0] = 1;
    for(int i=1;i<=1000;i++){
        ncr[i][0] = 1;
        for(int j=1;j<=i;j++)
            ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j]) % MOD;
    }

    cin>>n>>A>>B>>c>>d;
    memset(DP, -1, sizeof(DP));
    cout<<dp(n, A);
    return 0;
}



