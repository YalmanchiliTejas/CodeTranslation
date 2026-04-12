#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
using ll = long long;

void solve(long long N, std::vector<long long> A){
    ll sum = accumulate(A.begin(), A.end(), 0LL);
    ll ans = 0;
    for(int i = 0;i < N;i++){
        sum %= MOD;
        sum += MOD;
        sum -= A[i] % MOD;
        sum %= MOD;
        ans += sum * (A[i]) % MOD;
        ans %= MOD;
    }
    cout<<ans<<endl;
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
