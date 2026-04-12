#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define f first
#define se second
#define lb lower_bound
#define ub upper_bound
#define pii pair<double, double>
#define all(x) x.begin(), x.end()

const int N = 3000 + 144, mod = 1e9 + 7, inf = 1e9 + 7;
int n;
ll a[N];
ll pr[N];
ll dp[N][N];
bool was[N][N];

ll bp(ll x, ll y){
    if(y == 0)
        return 1;
    if(y & 1)
        return (x * bp(x, y - 1)) % mod;
    ll z = bp(x, y / 2);
    return (z * z) % mod;
}

ll rec(int l, int r){
    if(l == r)
        return a[l];
    if(was[l][r])
        return dp[l][r];
    dp[l][r] = pr[r] - pr[l - 1] - min(rec(l, r - 1), rec(l + 1, r));
    was[l][r] = true;
    return dp[l][r];
}

int main(){
    boost;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pr[i] = pr[i - 1] + a[i];
    }
    cout << -pr[n] + 2 * rec(1, n);
    return 0;
}
