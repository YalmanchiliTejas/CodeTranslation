#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; //check the limits, dummy
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; cin >> N;
    
    ll A[N]; F0R(i, N) cin >> A[i];
/*    if (N % 2 == 0) {
        ll X = 0, Y = 0;
        F0R(i, N) {
            if (i % 2) {
                X+=A[i];
            } else {
                Y+=A[i];
            }
        }
        cout << max(X, Y) << nl; return 0;
    }*/
    ll pref[N][2];
    pref[0][0] = A[0];
    pref[1][0] = A[1];
    for (int i = 2; i < N; i++) {
        pref[i][0] = pref[i-2][0] + A[i];
    }
    pref[N-2][1] = A[N-2];
    pref[N-1][1] = A[N-1];
    for (int i = N-3; i >= 0; i --) {
        pref[i][1] = pref[i+2][1] + A[i];
    }


    ll dp[N][3];
    F0R(i, N) F0R(j, 3) dp[i][j] = -1000000000000000;
    dp[0][0] = A[0]; 
    dp[0][1] = 0;
    dp[1][1] = max(A[1], A[0]);
    dp[1][2] = 0;
    if (N > 2) dp[2][0] = A[0] + A[2];
    if (N > 2) dp[2][2] = max(A[0], max(A[1], A[2]));

    FOR(i, 3, N) {
        F0R(j, 3) {
            if (j > 0) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
            }
            dp[i][j] = max(dp[i][j], A[i] + dp[i-2][j]);
        }
    }
    cout << dp[N-1][(N%2)+1] << nl;

/*    //case 0a: all odds
    ans = max(ans, pref[N-3][0]);
    ans = max(ans, pref[2][1]);
    //case 0b: all evens
    ans = max(ans, pref[1][1]);
    //case 1: all but one odd
    for (int i = 0; i < N-4; i+=2) {
        ans = max(ans, pref[i][0] + pref[i+4][1]);
    }
    //case 2: all odds, then some even
    for (int i = 0; i < N-3; i += 2) {
        ans = max(ans, pref[i][0] + pref[i+3][1]);
    }
    //case 2: all evens, then some odds
    for (int i = 1; i < N-3; i+=2) {
        ans = max(ans, pref[i][0] + pref[i+3][1]);
    }*/

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343

