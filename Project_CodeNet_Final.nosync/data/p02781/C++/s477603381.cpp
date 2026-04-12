#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n-1; i > 0; i--)
#define FOR(i, n, m) for(int i = n; i < (int)(m); i++)
#define PRINT(x) cout << x << endl
#define ALL(v) v.begin(), v.end()
#define INF (ll)1e18
#define PI 3.14159265358979

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll MOD = 1000000007;

int main()
{
    string N;
    cin >> N;
    ll K;
    cin >> K;
    vector<ll> n(N.length());
    REP(i, N.length()) n[i] = N[i] - '0';
    ll dp[101][2][5];
    REP(i, 101) {
        REP(j, 2) {
            REP(k, 5) {
                dp[i][j][k] = 0;
            }
        }
    }

    dp[0][0][0] = 1;
    REP(i, N.length()) {
        REP(j, 2) {
            REP(k, 4) {
                REP(l, j ? 10 : n[i]+1) {
                    dp[i+1][j || l < (n[i])][k + (l != 0)] += dp[i][j][k];
                }
            }
        }
    }
    PRINT(dp[N.length()][0][K] + dp[N.length()][1][K]);
    return 0;
}
