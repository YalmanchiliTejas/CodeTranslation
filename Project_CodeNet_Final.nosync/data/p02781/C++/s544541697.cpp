#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i,n,k) for(ll i=(n);i<(k);i++)
#define ALL(a)  (a).begin(),(a).end()
ll ans=0;
const ll MAX = 510000;
const ll MOD = 1000000007;

ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
ll COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
ll MODpow(ll a,ll n,ll mod=MOD) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
void Main(){
    COMinit();
    string s;cin>>s;
    ll n=s.size();
    ll k;cin>>k;
    ll cnt=0;
    For(i,0,n){
        if(cnt>k) break;
        if(s[i]!='0') {
            int keta=s[i]-'0';
            if(cnt==k){
                ans++;
            }
            else if(cnt==k-1){
                ans+=(keta-1)+9*COM(n-i-1,1);
            }
            else if(cnt==k-2){
                ans+=(keta-1)*9*COM(n-i-1,1)+9*9*COM(n-i-1,2);
            }
            else if(cnt==k-3){
                ans+=(keta-1)*9*9*COM(n-i-1,2)+9*9*9*COM(n-i-1,3);
            }
            cnt++;
        }
    }
    if(cnt==k) ans++;
    cout<<ans<<endl;
}
int main(){
    Main();
    return 0;
}