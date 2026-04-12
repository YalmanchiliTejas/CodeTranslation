#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl; 
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


//n!
ll fact_mod(ll n) {
    ll ret=1; 
    for(ll i=2;i<=n;i++) ret=ret*(i%mod)%mod;
    return ret;
}
 
// 繰り返し二乗法 
ll pow_mod(ll x, ll n){
    if(n==0) return 1;
    ll ret=pow_mod((x*x) % mod, n/2);
    if(n&1) ret=(ret*x)%mod;
    return ret;
}
 
//nCr O(r) nがでかくても安心
ll combination_mod(ll n, ll r) {
    if(r>n-r) r=n-r;
    if(r==0) return 1;
    ll a=1;
    //a=n!/(n-r)!=n~n-r+1までの総積->O(r)
    for(ll i=0;i<r;i++) a=a*((n-i)%mod)%mod;
    //b=inv(r!)
    ll b=pow_mod(fact_mod(r), mod-2);
    return (a%mod)*(b%mod)%mod;
}
 
ll inv_mod(ll n){
    // フェルマーの小定理
    return pow_mod(n,mod-2);
}



//cut here


const int MAX=510000;
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % mod;
        //???
        inv[i] = mod - inv[mod%i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}


signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    COMinit();
    
    vector<ll> dp(1010,0);dp[0]=1;
    ll n,a,b,c,d;cin>>n>>a>>b>>c>>d;

    //O(n^3)だけど実際はそんなにまわらないから許してや
    for(ll i=a;i<=b;i++){
        auto dp_new=dp;
        
        //i人グループをj個作る
        for(ll j=c;j<=d;j++){
            ll wake=fac[i*j];
            wake=(wake*inv_mod(  pow_mod(fac[i],j)  )  )%mod;
            wake=(wake*inv_mod(   fac[j]    ))%mod;
            if(i*j>n) break;
            rep(k,n){
                if(k+i*j>n) break;
                if(dp[k]==0) continue;
                ll kake=(wake*COM(n-k,i*j))%mod;
                dp_new[k+i*j]=(dp_new[k+i*j]+(dp[k]*kake)%mod)%mod;
            }
        }
        swap(dp,dp_new);
        // cout<<dp[n]<<endl;
        // rep(i,n+1)cout<<dp[i]<<' ';cout<<endl;
    }
    cout<<dp[n]%mod<<endl;
    return 0;
}
