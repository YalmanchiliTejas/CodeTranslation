#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep1(i,n) for(int i = 1; i <= (n); ++i)
#define MOD 1000000007
using namespace std;
typedef long long ll;

long long mod_inv(long long a, long long m){
    long long b = m, u = 1, v = 0;
    while(b){
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    ll ans;

    ll sum1 = 0;
    rep(i, N){
        sum1 = (sum1 + A[i]) % MOD;
    }

    ll sum2 = 0;
    rep(i, N){
        sum2 = (sum2 + A[i] * A[i]) % MOD;
    }

    ans = (sum1 * sum1 - sum2) % MOD;
    ans = ans * mod_inv(2, MOD);
    ans = ans % MOD;

    if(ans < 0) ans += MOD;

    cout << ans << endl;

    return 0;
}
