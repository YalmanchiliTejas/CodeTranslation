#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
using ll=long long;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)
#define endl "\n"
#define ALL(x) x.begin(),x.end()
#define ALLR(x) x.rbegin(),x.rend()
#define INF 1e9
#define DEBUG(x) cout<<"debug: "<<x<<endl

const int MOD = 1000000007;

int n;
int main() {
    cin >> n;
    vector<ll> a(n), b(n+1, 0);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) b[i+1] = b[i] + a[i];

    ll ans = 0;
    rep(i, 0, n){
        ll t = b[n] - b[i+1]; t %= MOD;
        ans += a[i]*t;
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}
