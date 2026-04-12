#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

const int INF = 1 << 30;
const ll LLINF = 1LL << 62;

int mod = 1000000007;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    ll A[N]; rep(i, N) cin >> A[i];
    ll sum[N+1] = {};
    rep(i, N) sum[i+1] = (sum[i] + A[i]) % mod;
    ll ans = 0;
    rep(i, N) ans = (ans + ((sum[N]-sum[i+1]) % mod)*A[i] % mod) % mod;
    if(ans < 0) ans += mod;
    cout << ans << endl;
    return 0;
}