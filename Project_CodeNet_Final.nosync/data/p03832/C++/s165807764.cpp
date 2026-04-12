#include <iostream>
using namespace std;
typedef long long ll;
ll kaijo[1010], a, b, c, d, n, dp[1010][1010];
const ll mod = 1000000007;

ll pow(ll x, ll y){
    if (y == 0) return 1;
    if (y % 2){
        return x * pow(x, y - 1) % mod;
    } else {
        ll han = pow(x, y / 2);
        return han * han % mod;
    }
}

int main(void){
    // Your code here!
    cin >> n >> a >> b >> c >> d;
    kaijo[0] = 1;
    for (ll i = 1; i <= 1000; i++) kaijo[i] = kaijo[i - 1] * i % mod;
    dp[a - 1][0] = 1;
    for (ll i = a; i <= b; i++){
        for (ll j = 0; j <= n; j++){
            (dp[i][j] += dp[i - 1][j]) %= mod;
            for (ll k = c; k <= min((n - j) / i, d); k++){
                (dp[i][j + i * k] += dp[i - 1][j] * kaijo[i * k] % mod * pow(pow(kaijo[i], k) * kaijo[k] % mod, mod - 2) % mod * kaijo[n - j] % mod * pow(kaijo[i * k] * kaijo[n - j - i * k] % mod, mod - 2) % mod) %= mod;
            }
        }
    }
    cout << dp[b][n] << endl;
}
