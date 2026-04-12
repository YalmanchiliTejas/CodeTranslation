#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 2e9
#define LINF 1e18
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (ll)(n); i++)
#define input(x, n)for(int i = 0; i <(ll)(n); i++)cin >> x[i];
#define until(i,n) for(int i = 1; i <= (ll)(n); i++)
#define all(x) (x).begin(),(x).end()
#define dump(x) cout << #x << "=" << (x) << endl
#define YES(n) cout << ((n) ? "YES" : "NO")
#define Yes(n) cout << ((n) ? "Yes" : "No")
#define PI 3.141592653589793

int main(){
    
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> B(n+1, 0);
    ll sum = 0;
    rep(i, n){
        cin >> a[i];
        B[i+1] = B[i]+a[i];
    }

    ll ans = 0;

    rep(i, n){
        ll sum = (B[n] - B[i+1])%MOD;
        ans += a[i]*sum;
        ans %= MOD;
    }

    cout << ans << endl;

}