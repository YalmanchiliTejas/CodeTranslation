#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
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
int main(){
    COMinit();
    ll n,m,k;
    cin>>n>>m>>k;
    ll ans=0;
    //全2点間マンハッタン
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ll t=((n-i)*((m-j)*(i+j))%mod)%mod;
            if(i!=0&&j!=0) t*=2;
            //ななめは二通りあるから2倍
            ans=(ans+t)%mod;
        }
    }

    ans=(ans*COM(n*m-2,k-2))%mod;

    cout<<ans<<endl;
    return 0;
}
