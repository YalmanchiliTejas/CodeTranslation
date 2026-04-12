#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, int> ri3;
#define mp make_pair
#define pb push_back
#define fi first
#define sc second
#define SZ(x) (int)(x).size()
#define ALL(x) begin(x), end(x) 
#define REP(i, n) for (int i = 0; i < n; ++i) 
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define RFOR(i, a, b) for (int i = a; i >= b; --i)

int main() {
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    string k; int d; cin >> k >> d;

    int n = k.length();
    const int mod = 1e9+7;

    int dp[n+1][2][d]; 
    memset(dp[n], 0, sizeof dp[n]);
    dp[n][0][0] = dp[n][1][0] = 1;

    RFOR(i,n-1,0) FOR(bnd,0,1) FOR(x,0,d-1) {
        int& a = dp[i][bnd][x] = 0;
        if (bnd) {
            FOR(y,0,k[i]-'1'){
                a = (a + dp[i+1][0][(x+y)%d]) % mod;
            }
            a = (a + dp[i+1][bnd][(x+(k[i]-'0'))%d]) % mod;
        } else {
            FOR(y,0,9){
                a = (a + dp[i+1][0][(x+y)%d]) % mod;
            }
        }
    }

    cout << (dp[0][1][0]-1+mod)%mod << endl;
}

