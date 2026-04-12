#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long MOD = 1000000007;

void solve(long long N, std::vector<long long> A){
    vector<long long> cumsum(N+1, 0);
    ll ans = 0;
    for(ll i = 0; i < N; ++i){
        cumsum[i+1] = cumsum[i] + A[i];
    }
    for(ll i = 0; i < N; ++i){
        ans += A[i] * ((cumsum[N] - cumsum[i+1]) % MOD);
        ans %= MOD;
    }
    cout << ans << endl;
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, std::move(A));
    return 0;
}
