#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

#define MAX_N 200000
#define MAX_M 200000
#define MOD 1000000007

#define INF 1 << 29

typedef long long Int;
typedef pair<Int, Int> P;

int N, M;
string S;

// long long dp[MAX_N + 2], rdp[MAX_N + 2];

// int all_color_is_same()
// {
//     long long rr = 1, bb = 1, rb = 0, br = 0;

//     for ( int i = 1; i < N; i++ )
//     {
//         long long nrr = ( rr + rb ) % MOD;
//         long long nbb = br;
//         long long nrb = rr;
//         long long nbr = ( bb + br ) % MOD;

//         rr = nrr;
//         bb = nbb;
//         rb = nrb;
//         br = nbr;
//     }

//     return ( rr + rb + br ) % MOD;
// }

// /**

/* S
の先頭の文字の最小連続回数を求める。ただし連続回数が偶数のものは無視する。
*/
int min_freq()
{
    // int l = 0;
    // while ( l < M && S[0] == S[l] ) l++;

    // int ans = ( l & 1 ) ? l : l + 1;

    // l = 0;
    // for ( int i = 0; i < M; i++ )
    // {
    //     if ( S[0] == S[i] )
    //         l++;
    //     else
    //     {
    //         if ( l & 1 ) ans = min( ans, l );
    //         l = 0;
    //     }
    // }
    // return ( l & 1 ) ? min( ans, l ) : ans;
    Int l = 0;
    while ( S[0] == S[l] ) l++;
    if ( l % 2 == 0 ) l++;
    Int limit = l;
    l = 0;
    for ( int i = 0; i < M; i++ )
    {
        if ( S[i] == S[0] )
            l++;
        else
        {
            if ( l % 2 == 1 ) limit = min( limit, l );
            l = 0;
        }
    }
    return limit;
}

// int solve()
// {
//     // 一色
//     if ( S.find( "R" ) == string::npos || S.find( "B" ) == string::npos )
//         return all_color_is_same();

//     // N が奇数
//     if ( N & 1 ) return 0;

//     int L = min_freq();

//     L = ( L + 1 ) >> 1;
//     N >>= 1;

//     dp[0] = rdp[0] = 1;
//     for ( int i = 1; i <= N + 1; i++ )
//     {
//         dp[i] = rdp[i - 1];
//         if ( i - L - 1 >= 0 ) dp[i] = ( dp[i] - rdp[i - L - 1] ) % MOD;
//         if ( dp[i] < 0 ) dp[i] += MOD;
//         rdp[i] = ( rdp[i - 1] + dp[i] ) % MOD;
//     }

//     long long res = 0;
//     for ( int i = 1; i <= L; i++ )
//         if ( N >= i ) res = ( res + dp[N - i] * 2 * i ) % MOD;

//     return res % MOD;
// }

// int main( int argc, char **argv )
// {
//     cin >> N >> M;
//     cin >> S;

//     int ans = solve();

//     cout << ans << endl;

//     return 0;
// }

Int all( Int n )
{ // no bb
    Int rr = 1, bb = 1, rb = 0, br = 0;
    for ( int i = 1; i < n; i++ )
    {
        Int nrr = ( rr + rb ) % MOD;
        Int nbb = br;
        Int nrb = rr;
        Int nbr = ( bb + br ) % MOD;
        rr = nrr;
        bb = nbb;
        rb = nrb;
        br = nbr;
    }
    return ( rr + rb + br ) % MOD;
}

Int tmp[216000];
Int rdp[216000];
Int dp[216000];
void calc( Int n, Int limit )
{
    dp[0] = 1;
    rdp[0] = 1;
    for ( int i = 1; i <= n + 1; i++ )
    {
        dp[i] = ( rdp[i - 1] -
                  ( ( i - limit - 1 ) >= 0 ? rdp[i - limit - 1] : 0 ) ) %
                MOD;
        if ( dp[i] < 0 ) dp[i] += MOD;
        rdp[i] = ( rdp[i - 1] + dp[i] ) % MOD;
    }
}

Int solve( Int n, Int limit )
{
    if ( n % 2 == 1 ) return 0;
    if ( limit % 2 != 1 ) exit( 1 );
    limit = ( limit + 1 ) / 2;
    n /= 2;
    Int res = 0;
    calc( n + 10, limit );
    for ( Int i = 1; i <= limit; i++ )
    {
        if ( n - i >= 0 ) res = ( res + dp[n - i] * 2 * i ) % MOD;
    }
    if ( res < 0 ) exit( 1 );
    return res % MOD;
}

int main()
{
    cin >> N >> M;
    cin >> S;

    if ( S.find( "R" ) == string::npos || S.find( "B" ) == string::npos )
    {
        cout << all( N ) << endl;
        return 0;
    }

    int limit = min_freq();
    // cout << limit << endl;
    cout << solve( N, limit ) << endl;
    return 0;
}
