#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,n) for ( int i = (a); i < (n); ++i)
#define REP(i,n) for( int i = 0; i < (n); ++i )
#define ALL(obj) (obj).begin(), (obj).end()

int64_t com( int64_t n, int64_t r)
{
    if( r < 0 || r > n ) return 0;
    else if( r == 0 ) return 1;
    else if( r == 1 ) return n;
    else if( r == 2 ) return (n*(n-1))/2;
    return (n*(n-1)*(n-2)) / 6;
}

int64_t lpow( long long N, long long K) 
{
    long long res = 1;
    for (int i = 0; i < K; ++i) res *= N;
    return res;
}

int64_t solve( int T, int N, int K )
{
    int64_t count = 0;

    if( T == 0 ) return 0;
    // 0xxxx
    count += com( N-1, K ) * lpow( 9, K );

    // 1xxxx ~ (T-1)xxxx
    count += com( N-1, K-1) * lpow( 9, K-1 ) * (T-1);

    return count;
}

int main()
{
    string S;
    int K;
    cin >> S;
    cin >> K;
    int N = S.size();

    int64_t count = 0;
    int idx = 0;

    if( N >= K ) {
        REP(m,K) {
            while( S[idx] == '0' && idx < N ) {
                idx++;
            }
            if ( idx >= N ) {
                break;
            }
            count += solve( S[idx] - '0', N - idx, K - m );
            if( m == K - 1 ) {
                count++;
            }
            idx++;
        }
    }
    cout << count << endl;
    return 0;
}