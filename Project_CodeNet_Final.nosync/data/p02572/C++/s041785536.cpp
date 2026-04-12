#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using vl  = vector<ll>;
using vvl = vector<vl>;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define per(i,n) for(int i = (n)-1; i >= 0; --i)
#define rng(i,a,b) for(int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

const ll MOD = 1e9 + 7;

int main() {
    ll N, sum = 0;
    cin >> N;
    vl A(N);
    rep(i,N) {
        cin >> A[i];
        sum += A[i];
    }
    ll ans = 0;
    rep(i,N) {
        ll tmp = (sum - A[i]) % MOD;
        (ans += (A[i]*tmp) % MOD) %= MOD;
        sum -= A[i];
    }
    cout << ans << endl;
    return 0;
}
