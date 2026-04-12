#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define pp pair<int,int>
#define ll long long
int inf=100000000;
ll INF=5000000000000000000;
ll MOD=1000000007;

ll mpow(ll x, ll n){
ll ans = 1;
while(n != 0){
if(n&1) ans = ans*x % MOD;
x = x*x % MOD;
n = n >> 1;
}
return ans;
}
ll kj(ll x){
ll s = 1;
for(ll i = 1; i <= x; i++){
s = s * i % MOD;
}
return s;
}
ll combination(ll a, ll b){
if(a == 0 && b == 0) return 1;
if(a < b || a < 0) return 0;
return (kj(a) * mpow(kj(b), MOD-2) % MOD) * mpow(kj(a-b), MOD-2) % MOD;
}

int main() {
    ll n,m,k;
    cin >> n >> m >> k;
    vector<vector<ll>> a(n+1,vector<ll>(m+1));
    for (ll i=1;i<n+1;i++){
        for (ll j=1;j<m+1;j++){
            a.at(i).at(j)=(((((i-1)*i)/2%MOD+((n-i)*(n-i+1))/2%MOD)*m)%MOD+((((j-1)*j)/2%MOD+((m-j)*(m-j+1))/2%MOD)*n)%MOD)%MOD;
            //cout << a.at(i).at(j) << " ";
        }
        //cout << endl;
    }
    ll ans=0;
    ll u=combination(n*m-2,k-2);
    for (int i=1;i<n+1;i++){
        for (int j=1;j<m+1;j++){
            ans=(ans+a.at(i).at(j)*u%MOD)%MOD;
        }
    }
    ans=ans*mpow(2,MOD-2)%MOD;
    cout << ans << endl;
}
