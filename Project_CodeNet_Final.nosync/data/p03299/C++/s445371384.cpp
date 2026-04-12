#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

const ll MOD = 1000000007;

ll modpow(ll x, ll n){
    ll res = 1, r = x;
    while(n){
        if(n % 2) res = res * r % MOD;
        r = r * r % MOD;
        n /= 2;
    }
    return res;
}

ll p[102];
ll h[102];

P dfs(ll left, ll right, ll height){
    ll lowest = MOD;
    for(int i = left; i < right; i++) lowest = min(lowest, h[i]);
    P d[102];
    ll c = 0;
    ll k = 0;
    ll last = left;
    for(int i = left; i < right; i++){
        if(h[i] == lowest){
            c++;
            if(i != last){
                d[k] = dfs(last, i, lowest);
                k++;
            }
            last = i + 1;
        }
    }
    if(last != right){
        d[k] = dfs(last, right, lowest);
        k++;
    }
    ll dp[102][102];
    for(int i = 0; i <= k; i++){
        for(int j = 0; j <= k; j++) dp[i][j] = 0;
    }
    dp[0][0] = 1;
    for(int i = 1; i <= k; i++){
        for(int j = 0; j <= i; j++){
            dp[i][j] = dp[i - 1][j] * d[i - 1].second % MOD;
            if(j) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * d[i - 1].first % MOD) % MOD;
        }
    }
    P res = P(0, 0);
    for(int j = 0; j <= k; j++){
        res.second = (res.second + dp[k][j] * p[c + j] % MOD) % MOD;
    }
    res.first = dp[k][k] * 2 % MOD;
    res.second = (res.second + MOD - res.first) % MOD;
    res.first = res.first * modpow(2, lowest - height - 1) % MOD;
    return res;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> h[i];
    p[0] = 1;
    for(int i = 1; i <= n; i++) p[i] = p[i - 1] * 2 % MOD;
    P ans = dfs(0, n, 0);
    cout << (ans.first + ans.second) % MOD << endl;
}
