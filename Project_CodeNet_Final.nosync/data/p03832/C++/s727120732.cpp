#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
const ll mod = 1000000007;

ll inv[1000000];
ll FactorialInv[1000000];
ll Factorial[1000000];
ll beki(ll a, ll b){
    if(b == 0){
        return 1;
    }
    ll ans = beki(a, b / 2);
    ans = ans * ans % mod;
    if(b % 2 == 1){
        ans = ans * a % mod;
    }
    return ans;
}
void init_combination(){
    inv[1] = 1;
    FactorialInv[1] = 1;
    Factorial[1] = 1;
    for(int i = 2; i < 1000000; i++){
        inv[i] = beki(i, mod - 2);
        Factorial[i] = Factorial[i - 1] * i % mod;
        FactorialInv[i] = FactorialInv[i - 1] * inv[i] % mod;
    }
}
ll combination(ll a, ll b){
    if((a == b) || (b == 0)){
        return 1;
    }
    ll ans = Factorial[a] * FactorialInv[b] % mod;
    ans = ans * FactorialInv[a - b] % mod;
    return ans;
}


int main() {
    init_combination();
    //cout.precision(10);
    ll dp[1005][1005];
    ll a, b, c, d, n;
    cin >> n >> a >> b >> c >> d;
    for(ll i = 0; i <= n; i++){
        for(ll j = 0; j <= n; j++){
            dp[i][j] = 0;
        }
    }
    dp[n][a - 1] = 1;
    //for(ll people = 1; people <= n; people++){
    for(ll checked = a; checked <= b; checked++){
        for(ll people = 0; people <= n; people++){
        //for(ll checked = a; checked <= b; checked++){
            dp[people][checked] += dp[people][checked - 1];
            dp[people][checked] = dp[people][checked] % mod;
            ll patterns = 1;
            for(ll groups = 1; groups <= d; groups++){
                if(people - groups * checked < 0){
                    break;
                }
                patterns = patterns * combination(people - checked * (groups - 1), checked) % mod;
                patterns = patterns * inv[groups] % mod;
                if(groups < c) continue;
                ll delta = dp[people][checked - 1] * patterns % mod;
                //dp[people - groups * checked][checked] = (dp[people - groups * checked][checked] + dp[people][checked - 1]) % mod;
                //dp[people - groups * checked][checked] = (dp[people - groups * checked][checked]) * patterns % mod;
                dp[people - groups * checked][checked] = (dp[people - groups * checked][checked] + delta) % mod;
            }
        }
    }
    /*for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            //cout << j << " " << i << " " << dp[j][i] << endl;
        }
    }*/
    cout << dp[0][b] << endl;
    return 0;
}
