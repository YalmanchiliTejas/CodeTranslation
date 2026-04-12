#include "iostream"
#include "algorithm"
#include "cstring"
#include "cstdio"
#include "cmath"
#include "vector"
#include "map"
#include "set"
#include "queue"
using namespace std;
#define MAXN 3006
//#define int long long
#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define mem( a ) memset( a , 0 , sizeof a )
#define P 998244353
typedef long long ll;
int n , s , k;
int A[MAXN] , dp[MAXN][MAXN];
void solve( ) {
    cin >> n >> s;
    for( int i = 1 ; i <= n ; ++ i ) scanf("%d",A + i);
    long long ans = 0;
    for( int i = 1 ; i <= n ; ++ i ) {
        for( int j = 1 ; j <= s ; ++ j ) dp[i][j] = dp[i - 1][j];
        for( int j = A[i] ; j <= s ; ++ j ) ( dp[i][j] += dp[i - 1][j - A[i]] ) %= P;
        ( dp[i][A[i]] += i ) %= P;
        ( ans += 1ll * ( dp[i][s] - dp[i - 1][s] + P ) % P * ( n - i + 1 ) % P ) %= P;
    }
    cout << ans << endl;
}
signed main() {
//    int T;cin >> T;while( T-- ) solve();
    solve();
}
