#include <bits/stdc++.h>
#define SORT(x) sort((x).begin(), (x).end())
#define ALL(x) (x).begin(), (x).end()
#define rep(i, n) for (ll i = 0; i < n; i++)
#define reps(i, m, n) for (ll i = m; i < n; i++)
#define repr(i, m, n) for (ll i = m; i >= n; i--)
#define de(x) cout << #x << "=" << x << endl;
template <class T> bool maxi(T &a, const T &b) {
    if (a < b) { a = b; return 1;} return 0;}
template <class T> bool mini(T &a, const T &b) {
    if (b < a) { a = b; return 1;} return 0;}
#define dame {cout<< "NO" <<"\n"; return;}
#define INF2 1000000000000000037
#define INF  1000000007
#define MOD  1000000007
using namespace std;
using ll = long long;
using ld = long double;
using P  = pair<ld,ll>;
//--GLOBAL---------------------------------
const ll MAX = 202020;
ll fac[MAX], finv[MAX], inv[MAX];
void cinit() { // O(nlogn)
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    reps(i, 2, MAX){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
ll c(int n, int k){ // 二項係数計算
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
ll modpow(ll a, ll n=MOD-2, ll mod=MOD){ // a^n % MOD の計算
    ll res = 1;
    while (n > 0){
        if(n & 1) res = res * a % mod;
        a = a * a  % mod;
        n >>= 1;
    }
    return res;
}
//--MAIN-----------------------------------
void Main() {

    ll N,A,B,C,D; cin>>N>>A>>B>>C>>D;
    cinit();
    ll dp[N+1][N+1]={}; //j人使ってi人までのグループ作る
    dp[A-1][0]=1;
    reps(i,A-1,B){
        rep(j,N+1){
            ll x=i+1;
            // i+1人を0グループ作る
            dp[x][j]+=dp[i][j];
            dp[x][j]%=MOD;
            // i+1人をkグループ作る
            //if(j+x*C>N) continue;
            ll now=1;
            reps(k,1,C){
                now*=c(N-j-x*(k-1),x);
                now%=MOD;
            }
            for(ll k=C; j+x*k<=N and k<=D; ++k){
                now*=c(N-j-x*(k-1),x);
                now%=MOD;
                dp[x][j+x*k]+=(dp[i][j]*now%MOD)*finv[k];
                dp[x][j+x*k]%=MOD;
            }
        }
    }
    cout<< dp[B][N] <<"\n";

}
 
//--START----------------------------------
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
//-----------------------------------------