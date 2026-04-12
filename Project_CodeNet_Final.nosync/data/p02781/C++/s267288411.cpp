#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define lcm( a, b ) (a)/__gcd((a),(b))*(b)
#define endl '\n'

using namespace std;

typedef long long LL;
typedef pair< int, int > P;
typedef pair< LL, LL > LP;

static const int INF = INT_MAX;
static const LL LINF = LLONG_MAX;
static const int MIN = INT_MIN;
static const LL LMIN = LLONG_MIN;
static const int MOD = 1000000007;
static const int SIZE = 200005;

const int dx[] = {0, -1, 1, 0};
const int dy[] = {-1, 0, 0, 1};

LL fac[SIZE], finv[SIZE], inv[SIZE];
void combInit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for( int i = 2; i < SIZE; ++i ) {
        fac[i] = (fac[i - 1] * i) % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = (finv[i - 1] * inv[i]) % MOD;

    }
}

LL comb(int n, int k) {
    if( n < k ) return 0;
    if( n < 0 || k < 0 ) return 0;
    return (fac[n] * (finv[k] * finv[n - k] % MOD)) % MOD;

}

vector< int > Div( int n ) {
    vector< int > ret;
    for( int i = 1; i * i <= n; ++i ) {
        if( n % i == 0 ) {
            ret.pb( i );

            if( i * i != n ) ret.pb( n / i );
        }
    }
    sort( all( ret ) );
    return ret;
}

LL dp[105][2][4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int k;
    cin >> k;
    // 1 -> smaller 0 -> exact
    for( int i = 0; i < s.size(); ++i ) {
        int nu = s[i] - '0';
        if( i == 0 ) {
            dp[i][1][1] = nu - 1;
            dp[i][0][0] = 0;
            dp[i][0][1] = 1;
            dp[i][1][0] = 1;

        } else {
            // sm -> sm
            for( int j = 0; j <= k; ++j ) {
                if( j == 0 ) {
                    dp[i][1][0] += dp[i - 1][1][0];

                } else {
                    dp[i][1][j] += dp[i - 1][1][j - 1] * 9;
                    dp[i][1][j] += dp[i - 1][1][j];

                }
            }

            int tmp = nu;
            if( nu != 0 ) {
                --nu;
                // exact -> smaller
                for( int j = 1; j <= k; ++j ) {
                    if( nu == 0 ) dp[i][1][j] += dp[i - 1][0][j];
                    else {
                        dp[i][1][j] += dp[i - 1][0][j - 1] * nu;
                        dp[i][1][j] += dp[i - 1][0][j];
                    }
                }
            }

            // exact -> exact
            for( int j = 0; j <= k; ++j ) {
                if( tmp != 0 ) {
                    if( j != 0 ) dp[i][0][j] = dp[i - 1][0][j - 1];

                } else {
                    dp[i][0][j] = dp[i - 1][0][j];

                }

            }
        }
    }
    cout << dp[s.size() - 1][0][k] + dp[s.size() - 1][1][k] << endl;

    return 0;
}

