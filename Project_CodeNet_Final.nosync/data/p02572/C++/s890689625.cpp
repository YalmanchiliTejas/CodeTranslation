#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
//__uint128_t
const ll MOD = 1e9+7;

int main(){
    ll N; cin >> N;
    vector<__uint128_t> V(N), W(N);
    for(int i = 0; i < N; i++) {
        ll x; cin >> x;
        V[i] = W[i] = x;

    }
    for(int i = N-2; i >= 0; i--) V[i] = V[i] + V[i+1];
    __uint128_t ans = 0;
    for(int i = 0; i < N-1; i++) {
        //ans = (ans + W[i] * V[i+1]) % MOD;
        ans += W[i] * V[i+1];
        ans %= MOD;
    }
    cout << (ll)ans << endl;

}