#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define rep1(i,n) for(int i=1; i<=(n); ++i)
#define repi(i,a,b) for(int i=a; i<=(b); ++i)
#define rrep(i,n) for(int i=(n-1); i>=0; --i)
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define pb push_back
#define mp make_pair
#define sz(v) (int)v.size()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
using ll = long long;
using namespace std;
typedef pair<int,int> P;
struct aaa{aaa(){ cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(20);};}aaaaaaa;
ll MOD = 1e9 + 7;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return (a*b)/gcd(a,b);}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

const int MAX = 510000;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll N,M,K;
int main(){
    cin >> N >> M >> K;
    COMinit();
    ll com = COM(N*M-2,K-2);
    ll ans = 0;
    rep(d,N) ans += d*(N-d)*M*M, ans %= MOD;
    rep(d,M) ans += d*(M-d)*N*N, ans %= MOD;
    cout << (ans*com)%MOD << '\n';
}