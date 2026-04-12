#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using stkll = vector<pll>;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
#define rep(i, n) for (ll i = 0; i < (n); i++)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << ": " << x << endl;
#else
    #define debug(x)
#endif

const int MAX = 510000;

long long fac[MAX], finv[MAX], inv[MAX];
void COMinit(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    COMinit();
    string S;
    ll K;
    cin >> S >> K;
    ll ans = 0, N = S.size();
    ans += COM(N-1, K) * pow(9, K);
    ans += ((S[0]-'0') - 1) * COM(N-1, K-1) * pow(9, K-1);

    if(K == 1) {
        ans++;
        cout << ans << endl;
        return 0;
    }

    string T = "";
    T += S[0];
    rep(i, N-1) T += '0';

    if(K == 2) {
        for(ll i = 1; i < N; i++) {
            string U = T;
            for(char x = '1'; x <= '9'; x++){
                U[i] = x;
                if(U <= S) ans++;
            }
        }
        cout << ans << endl;
        return 0;
    }

    for(ll i = 1; i < N; i++) {
        for(ll j = i+1; j < N; j++) {
            string U = T;
            for(char x = '1'; x <= '9'; x++) for(ll y = '1'; y <= '9'; y++) {
                U[i] = x, U[j] = y;
                if(U <= S) ans++;
            }
        }
    }
    cout << ans << endl;
}
