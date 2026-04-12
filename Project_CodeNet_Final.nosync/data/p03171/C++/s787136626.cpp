#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll, ll>;
using iii = pair<ii, ll>;
#define vt vector
#define pq priority_queue
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define __lcm(a, b) a * b / __gcd(a, b)x
const ll MOD = 1e9 + 7;
const ll INF = 2e9;
const ll N = 3e3 + 5;

ll n, k;
ll a[N];
ll dp[N][N];

ll f(ll l, ll r) {
    if(l > r) return 0;
    ll &sol = dp[l][r];
    if(sol != -1) return sol;
    return sol = max(a[l] - f(l + 1, r), a[r] - f(l, r - 1));
}

void solve() {
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << f(1, n) << "\n";
}

int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    
}