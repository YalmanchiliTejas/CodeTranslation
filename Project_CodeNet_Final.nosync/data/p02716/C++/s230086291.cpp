#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;
typedef long long ll;
ll a[maxn];
ll dp[maxn][2];
ll si[maxn], sp[maxn];
int memo[maxn][2];

ll solve( int n, int k ){

    if( !k ) return 0;
    if( k > (n+1)/2 ) return -1LL << 50;
    if( n == 3 && k == 2 )
        return a[1] + a[3];
    if( n == 3 && k == 1 )
        return max({a[1], a[2], a[3]});
    if( n == 4 && k == 1 )
        return max({a[1], a[2], a[3], a[4]});
    if( n == 4 && k == 2 ){
        ll ret = -1LL << 50;
        for( int i = 1; i <= 2; i++ )
            for( int j = i+2; j <= 4; j++ )
                ret = max(ret, a[i] + a[j]);
        return ret;
    }
    if( n == 2 && k == 1 )
        return max(a[1], a[2]);

    if( n % 2 == 0 ){
        int kk = n/2;
        if( k > kk ) return -1LL << 50;
        if( memo[n][0] ) return dp[n][0];
        memo[n][0] = 1;
        ll val = max( a[n] + solve(n-2, k-1), solve(n-1, k) );
        dp[n][0] = val;
        return val;
    }
    else{
        if( k == (n+1)/2 )
            return si[n];
        if( k == n/2 ){
            if( memo[n][0] ) return dp[n][0];
            memo[n][0] = 1;
            ll val = max( {a[n] + solve(n-2, k-1), solve(n-1, k), solve(n-2, k)} );
            dp[n][0] = val;
            return val;
        }
    }
    return 0;

}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifdef acm
    freopen("a.in","r",stdin);
    #endif // acm

    int n;
    cin >> n;

    for( int i = 1; i <= n; i++ ){
        cin >> a[i];
        si[i] = si[i-1];
        sp[i] = sp[i-1];
        if( i & 1 )
            si[i] += a[i];
        else sp[i] = sp[i-1];
    }

    int k = n/2;

    cout << solve(n, k) << "\n";
    return 0;
}
