#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
ll mod = -1;
ll N;
ll ans = 0;
ll inv[10000100];
ll FactorialInv[10000100];
ll Factorial[10000100];
ll beki(ll a, ll b, ll mod){
    a %= mod;
    if(b == 0){
        return 1;
    }
    ll ans = beki(a, b / 2, mod);
    ans = ans * ans % mod;
    if(b % 2 == 1){
        ans = ans * a % mod;
    }
    return ans;
}
void init_combination(){
    const int MAX = 10000002;
    Factorial[0] = 1;
    inv[0] = 1;
    for(int i = 1; i <= MAX; i++){
        Factorial[i] = Factorial[i - 1] * i % mod;
    }
    FactorialInv[MAX] = beki(Factorial[MAX], mod - 2, mod);
    for(ll i = MAX - 1; i >= 0; i--) {
        FactorialInv[i] = FactorialInv[i+1] * (i+1) % mod;
    }
    for(int i = 1; i <= MAX; i++) {
        inv[i] = FactorialInv[i] * Factorial[i-1] % mod;
    }
}
ll combination(ll a, ll b){
    if((a == b) || (b == 0)){
        return 1;
    }
    if(a < b) return 0;
    ll ans = Factorial[a] * FactorialInv[b] % mod;
    ans = ans * FactorialInv[a - b] % mod;
    return ans;
}

ll dp[3005][3005];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> mod;
    init_combination();
    for(ll num = 0; num <= 3000; num++) {
        dp[num][0] = 1;
        for(ll box = 1; box <= 3000; box++) {
            if(num >= 1) dp[num][box] += box * dp[num-1][box];
            if(num >= 1) dp[num][box] += dp[num-1][box];
            if(num >= 1 and box >= 1) dp[num][box] += dp[num-1][box-1];
            dp[num][box] %= mod;
        }
    }
    for(int i = 0; i <= 5; i++) {
        for(int j = 0; j <= 5; j++) {
            //cerr << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    /*
    cerr << beki(2, beki(2, 3)) << endl;
    cerr << beki(2, 3) << endl;
    cerr << beki(2, 8) << endl;
    */
    for(ll i = 0; i <= N; i++) {
        ll now = 0;
        //cerr << "---" << i << "---" << endl;
        ll factor = beki(2, N - i, mod);
        for(ll box = 0; box <= i; box++) {
            ll tmp = dp[i][box];
            tmp *= beki(factor, box, mod);
            tmp %= mod;
            //cerr << box << " " << tmp << endl;
            now += tmp;
        }
        now %= mod;
        //cerr << now << " ";
        now *= beki(2, beki(2, N - i, mod - 1), mod);
        now %= mod;
        //cerr << now << " ";
        now *= combination(N, i);
        now %= mod;
        //cerr << now << " ";
        //cerr << endl;
        if(i % 2 == 0) ans += now;
        else ans += (mod - now);
        ans %= mod;
    }
    ans %= mod;
    ans += mod;
    ans %= mod;
    cout << ans << endl;
    return 0;
}
