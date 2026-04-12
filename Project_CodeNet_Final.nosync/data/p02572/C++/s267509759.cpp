#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 2e9
#define LINF 1e18
#define PRM 1000000007
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
    ll sum = 0;
    rep(i, n){
        cin >> a[i];
        sum += a[i];
    }
 
    ll ans = 0;
 
    rep(i, n){
        sum -= a[i];
        ans += (sum%PRM)*a[i];
        ans %= PRM;
    }
 
    cout << ans << endl;
 
}