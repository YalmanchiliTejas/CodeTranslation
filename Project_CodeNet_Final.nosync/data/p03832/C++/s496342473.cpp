#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define fi first
#define se second
#define rep(i,s,n) for(int i = s;i<n;i++)
#define rrep(i,s,n) for(int i = (n)-1;i>=(s);i--)
#define all(v) (v).begin(),(v).end()
#define chmin(a,b) a=min((a),(b))
#define chmax(a,b) a=max((a),(b))
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0)
typedef long long ll;
typedef pair<int,int>pint;
typedef vector<int>vint;
const ll MOD=1000000007,INF=1e18;
 
int N,A,B,C,D;
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
ll mod_pow(ll x, ll n) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * x % MOD;
		x = x * x % MOD;
		n >>= 1;
	}
	return res;
}
 
int mod_inv(int x)
{
	return mod_pow(x, MOD - 2);
}
 
int dp[2020][2020];
 
signed main() {
    IOS();
    COMinit();
    cin>>N>>A>>B>>C>>D;
    dp[A][0]=1;
    
    rep(i,A,B+1){
        rep(j,0,N+1){
            (dp[i+1][j]+=dp[i][j])%=MOD;
            int t=dp[i][j];
            rep(k,1,D+1){
                if(N<j+i*k)break;
                t*=COM(N-j-i*(k-1),i);
                t%=MOD;
                t*=mod_inv(k);
                t%=MOD;
                if(k>=C)(dp[i+1][j+i*k]+=t)%=MOD;
            }
        }
    }
    cout<<(dp[B+1][N])%MOD<<endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}