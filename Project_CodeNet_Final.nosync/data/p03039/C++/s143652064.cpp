#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

const int MOD = 1e+9 + 7;

template <typename T>
T pow_mod( T n, T p )  // n^p % m
{
    if( p == 0 ) return 1;
    if( p%2 == 1 ) return pow_mod(n, p-1) * n % MOD;
    else{
        T tmp = pow_mod(n, p/2) % MOD;
        return tmp*tmp % MOD;
    }
}

template <typename T>
T nCk_mod( T n, T k )
{
    if( n < 0 or k < 0 || n < k ) return 0;
    T numerator = 1, denominator = 1;
    for( int i = 1; i <= min(k, n-k); ++i ){
        numerator = numerator*(n-i+1) % MOD;
        denominator = denominator*i %MOD;
    }
    return numerator * pow_mod<T>(denominator, MOD-2) % MOD;
}

int main()
{
    long long N, M, K;
    cin >> N >> M >> K;

    long long fact = nCk_mod<long long>(N*M-2, K-2);

    long long ans = 0;
    // x 方向
    FOR(i, 1, N){  // |x_i - x_j| == i のものを考える
        ans += i * (N-i) * M*M * fact % MOD;
        ans %= MOD;
    }
    // y 方向
    FOR(i, 1, M){
        ans += i * (M-i) * N*N * fact % MOD;
        ans %= MOD;
    }
    cout << ans << endl; 
    
    return 0;
}