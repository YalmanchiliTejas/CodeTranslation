#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

const ll mod = 1000000000 + 7;
int main(){
    ll n;
    cin >> n;
    VL a(n), acc(n+1, 0);
    rep(i, 0, n) cin >> a[i];
    for(ll i = n-1; i>=0; i--) acc[i] = (acc[i+1] + a[i]) % mod;
    ll ans = 0;
    rep(i, 0, n) {
        ans += (acc[i+1] * a[i]) % mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}