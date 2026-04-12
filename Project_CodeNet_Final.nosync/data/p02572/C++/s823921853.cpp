#include <bits/stdc++.h>
#define rep(i, N) for(ll i = 0; i < N; i++)
using ll = long long;
using namespace std;
#define MOD 1000000007
typedef pair<ll,ll> Pl;
typedef vector<ll> vl;

int main() {
    int n;
    cin >> n;
    ll a[202020];
    rep(i,n) scanf("%lld", &a[i]);

    ll sum = 0, ans = 0;
    rep(i,n) {
        sum += a[i];
        if(sum >= MOD) sum %= MOD;
    }
    rep(i,n-1){
        sum -= a[i];
        if(sum < 0) sum = (sum + MOD) % MOD;
        ans += (a[i] * sum)%MOD;
        if(ans >= MOD) ans %= MOD;
    }

    cout << ans;
    printf("\n");
}
