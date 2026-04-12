#include <bits/stdc++.h>
 
using namespace std;
 
using usize = ::std::size_t;
using u64 = ::std::int_least64_t;
//using u64 = int;
static constexpr u64 Inf = ::std::numeric_limits<u64>::max() / 2;
 
 #define MOD 1000000007

long long mod(long long val, long long m) {
  long long res = val % m;
  if (res < 0) res += m;
  return res;
}

int main(int argc, char *argv[])
{
    
 
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<u64> A(N + 1), S(N, 0);
    u64 sum = 0;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        sum += A[i];
        sum %= MOD;
    }
    S[0] = sum;
    u64 ans = 0;
    for (int i = 1; i < N; i++) {
        S[i] = mod((S[i - 1] % MOD) - (A[i] % MOD), MOD);
        ans += (S[i] * A[i]);
        ans %= MOD;
    }
    
    cout << ans << endl;

    
    return 0;
    
}
