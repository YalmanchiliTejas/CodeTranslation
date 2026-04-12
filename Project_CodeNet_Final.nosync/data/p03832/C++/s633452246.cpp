#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<string>
#include<iomanip>
#include<bitset>

using namespace std;

#define ll long long int

ll const MOD = 1000000007;
ll const INF = (long long int)1 << 61;

class Combination{
    long long int maxn;
    long long int mod;
    std::vector<long long int> factorial;
    std::vector<long long int> inverse;

    public:

    Combination(long long int n,long long int m):maxn(n),mod(m){
        factorial.push_back(1);
        inverse.push_back(1);

        for(long long int i = 1; i <= n; i++){
            factorial.push_back((factorial.back()*i)%mod);
            inverse.push_back([&](long long int x,long long int n) -> long long int{
                long long int ret = 1;
                while(n > 0){
                    if(n&1)ret = (ret*x)%mod;
                    x = (x*x)%mod;
                    n >>= 1;
                }
                return ret;
            }(factorial.back(),mod-2));
        }
    }

    long long int getFactorial(int idx){
        if(idx > maxn || idx < 0)return -1;
        return factorial[idx];
    }

    long long int getInverse(int idx){
        if(idx > maxn || idx < 0)return -1;
        return inverse[idx];
    }

    long long int comb(long long int n,long long int r){
        return (((factorial[n]*inverse[n-r])%mod)*inverse[r])%mod;
    }
};

ll mypow(ll x,ll n){
    ll ret = 1;
    while(n > 0){
        if(n&1){
            ret *= x;
            ret %= MOD;
        }
        x *= x;
        x %= MOD;
        n >>= 1;
    }
    return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll n,a,b,c,d;
    cin >> n >> a >> b >> c >> d;

    vector<vector<ll>> dp(b-a+2,vector<ll>(n+1,0));
    dp[0][0] = 1;
    Combination cb = Combination(n+1,MOD);
    
    for(ll i = 0; i < b-a+1; i++){
        for(ll j = 0; j < n+1; j++){
            dp[i+1][j] += dp[i][j];
            dp[i+1][j] %= MOD;
            for(ll k = c; k <= d; k++){
                if((a+i)*k+j > n)break;
                dp[i+1][(a+i)*k+j] += (((((((dp[i][j]*cb.getInverse(j))%MOD)*cb.getFactorial((a+i)*k+j))%MOD)*mypow(cb.getInverse(a+i),k))%MOD)*cb.getInverse(k))%MOD;
                dp[i+1][(a+i)*k+j] %= MOD;
            }
        }
    }


    cout << dp.back()[n] << endl;
    
    return 0;
}