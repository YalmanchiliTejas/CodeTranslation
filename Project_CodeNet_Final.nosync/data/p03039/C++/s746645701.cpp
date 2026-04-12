#include <bits/stdc++.h>
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define reprrev(i,a,b) for(int i=b-1;i>=a;i--) // [a, b)
#define reprev(i,n) reprrev(i,0,n)
typedef long long ll;
typedef unsigned long long ull;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
*/

const ll mod = 1e9+7;

void chmod(ll &M){
    if(M >= mod) M %= mod;
    else if(M < 0){
        M += (abs(M)/mod + 1)*mod;
        M %= mod;
    }
}

ll modpow(ll x, ll n){
    if(n==0) return 1;
    ll res=modpow(x, n/2);

    if(n%2==0) return res*res%mod;
    else return res*res%mod*x%mod;
}

int getl(int i, int N) { return i==0? N-1:i-1; };
int getr(int i, int N) { return i==N-1? 0:i+1; };


// 線分 ab の偏角 返り値は[-π, π]
double argument(const pair<double, double> &a, const pair<double, double> &b){
    double ax=a.first, ay=a.second, bx=b.first, by=b.second;
    return atan2(by-ay, bx-ax);
}

/* <-----------------------------------------------------------------------------------> */
/* <-----------------------------------------------------------------------------------> */
/* <-----------------------------------------------------------------------------------> */
/* <-----------------------------------------------------------------------------------> */


//const int mod = 1000000007;
const int MAX = 1000005;

long long fac[MAX], finv[MAX], inv[MAX];
void COMinit(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < MAX; i++){
        fac[i] = fac[i-1] * i % mod;
        inv[i] = mod - inv[mod%i] * (mod/i) % mod;
        finv[i] = finv[i-1] * inv[i] % mod;
    }
}
long long COM(int n, int k){
    if(n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n-k] % mod) % mod;
}


// パスカルの三角形を使った実装
ll C[51][51]; // C[n][k] -> nCk

void comb_table(int N){
    for(int i=0; i<=N; i++){
        for(int j=0; j<=i; j++){
            if(j==0 || j==i) C[i][j] = 1LL;
            else C[i][j] = (C[i-1][j-1]+C[i-1][j]);
        }
    }
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    COMinit();
    ll N, M, K; cin >> N >> M >> K;
    ll ans = 0;
    
    repr(a, 1, N) {
        ll add = a * (N-a) % mod * M % mod * M % mod * COM(N*M-2, K-2) % mod;
        ans += add;
        chmod(ans);
    }

    repr(a, 1, M) {
        ll add = a * (M-a) % mod * N % mod * N % mod * COM(N*M-2, K-2) % mod;
        ans += add;
        chmod(ans);
    }

    cout << ans << endl;

    return 0;
}


