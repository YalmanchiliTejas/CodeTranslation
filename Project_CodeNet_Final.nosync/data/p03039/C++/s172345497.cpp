#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    ll N, M, K;
    cin >> N >> M >> K;

    vector<ll> inv(200005); inv[1] = 1;
    for (int i = 2; i < 200005; i++) {
        inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
    }

    ll ans = 1;
    for (ll i = 0; i < K-2; i++) {
        ans = ans * (N*M - 2 - i) % MOD;
        ans = ans * inv[1+i] % MOD;
    }
    ans = ans * inv[6] % MOD;
    ll tmp = 0;
    tmp = M*N*(M+N) % MOD;
    tmp = (tmp + MOD - (M+N)) % MOD;
    tmp = tmp * M * N % MOD;

    ans = ans * tmp % MOD;

    printf("%lld\n", ans);


}
