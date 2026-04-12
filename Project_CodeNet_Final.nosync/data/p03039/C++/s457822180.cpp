#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(i,n) for(int i=0;i<n;i++)
#define ifr(i,n) for(int i=n-1;i>=0;i--)

const int MAX = 510000;
const int MOD = 1000000007;

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

int main() {
  COMinit();
    ll n,m,k;
    ll a=1000000007;
    ll ans=0;
    ll kai=0;
	cin >> n >>m >>k;
    fr(i,n){
      kai+=i*(n-i)*m*m;
      kai%=a;
    }
    kai*=COM(n*m-2,k-2)%a;
    ans+=kai;
    kai=0;
    fr(i,m){
      kai+=i*(m-i)*n*n;
      kai%=a;
    }
    kai*=COM(n*m-2,k-2)%a;
    ans+=kai;
    ans%=a;
    cout << ans<<endl; 
}
