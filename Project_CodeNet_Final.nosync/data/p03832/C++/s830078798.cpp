#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp setprecision
#define pb(x) push_back(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ld, ld> pdd;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e8;
const ll INF = 1e16;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

const int MAX_N = 2e6;
ll fac[MAX_N+1], ifac[MAX_N+1], inv[MAX_N+1];

//mpow(x,n)で(x^n)をO(log(n))で計算
ll mpow(ll x, ll n){
    ll res = 1, now = x;
    while(n > 0){
        if(n%2 == 1) res *= now, res %= MOD;
        now *= now, now %= MOD;
        n /= 2;
    }
    return res;
}

//setcomb()でfac,ifac,invを全て計算
void setcomb(){
    rep2(i, 1, MAX_N){
        inv[i] = mpow(i, MOD-2);
    }
    //i!とi!の逆元
    fac[0] = 1, ifac[0] = 1;
    rep2(i, 1, MAX_N){
        fac[i] = (fac[i-1]*i) % MOD;
        ifac[i] = (ifac[i-1]*inv[i]) % MOD;
    }
}

//comb(n, k)でnCk
ll comb(int n, int k){
    ll c = fac[n];
    c *= ifac[n-k], c %= MOD;
    c *= ifac[k], c %= MOD;
    return c;
}

//perm(n, k)でnPk
ll perm(int n, int k){
    return(fac[n]*ifac[n-k])%MOD;
}

int main(){
    setcomb();
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    //dp[i][j]:=すべてのグループの人数がi人以下になるようにj人を割り振る場合の数
    ll dp[B+1][N+1];
    fill(dp[0], dp[B+1], 0);
    rep(i, A){
        dp[i][0] = 1;
    }
    rep2(i, A, B){
        rep(j, N+1){
            dp[i][j] += dp[i-1][j];
        }
        //num[k]:=i*k人をi人ずつのk個のグループに分ける方法
        ll num[D+1];
        num[0] = 1;
        rep2(k, 1, D){
            num[k] = (num[k-1]*comb(i*k, i))%MOD;
            num[k] = (num[k]*inv[k])%MOD;
        }
        //i人のグループをk個使う
        rep2(k, C, D){
            if(i*k > N) break;
            rep2(j, i*k, N){
                ll tmp = (comb(j, i*k)*dp[i-1][j-i*k])%MOD;
                tmp = (tmp*num[k])%MOD;
                dp[i][j] = (dp[i][j]+tmp)%MOD;
            }
        }
    }
    cout << dp[B][N] << endl;
}