#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

typedef long long ll;
typedef pair<ll, ll> P;

const int mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 11

int main()
{
    int n; cin >> n;
    ll a[n];
    rep(i,n) cin >> a[i];
    vector<ll> v;
    ll sum = 0;
    rep(i,n){
        sum += a[i];
        sum %= mod;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        sum -= a[i];
        sum = (sum + mod*2) % mod;
        ans += a[i]*sum;
        ans %= mod;
    }
    cout << ans << endl;
}