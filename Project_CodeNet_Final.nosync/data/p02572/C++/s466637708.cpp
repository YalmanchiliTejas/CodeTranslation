#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
#define FOR(i, m, n) for(ll i = m; i < (n); i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
using vi = vector<int>;
using vii = vector<vi>;
using pii = pair<int, int>; 
using vl = vector<ll>;
using vll = vector<vl>;
using pll = pair<ll, ll>;

int main() {
    const ll mod = 1000000007;
    ll N;
    cin >> N;
    vl A(N), sum(N+1);
    rep(i, N){
        cin >> A[i];
    }
    sum[0] = 0;
    rep(i, N){
        sum[i+1] = sum[i] + A[i];
    }

    ll ans = 0;
    rep(i, N){
        ans += A[i] * ((sum[N]-sum[i+1])%mod) % mod;
        ans %= mod;
    }
    cout << ans;
}
