#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
#include <iomanip>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<long double> VD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

template<typename T> void chmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T &a, T b) { if (a < b) a = b; }

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }
#define INF 1LL<<60

int main() {
    int N, S, mod = 998244353;
    cin >> N >> S;
    vector<int> A(N+1);
    REP(i, N) cin >> A[i+1];
    vector< vector<int> > dp(N+1, vector<int>(S+5, 0));
    REP(i, N+1)
        dp[i][0] = 1;
    FOR(i, 1, N) {
        FOR(s, 0, S) {
            if(s - A[i] >= 0)
                dp[i][s] += dp[i-1][s] + dp[i-1][s - A[i]];
            else
                dp[i][s] += dp[i-1][s];
            
            dp[i][s] %= mod;
        }
    }

    // FOR(i, 1, N) {
    //     FOR(s, 0, S) cerr << dp[i][s] << " ";
    //     cerr << endl;
    // }
    int ans = 0;
    FOR(i, 1, N) {
        ans += dp[i][S];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}