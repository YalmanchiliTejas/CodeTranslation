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
    int N;
    cin >> N;
    vector<ll> A(N+1);
    REP(i, N) {
        cin >> A[i+1];
    }

    // dp[i][j]][k]: i番目までj個選び、k=0の場合iを使わない, k=1の場合iを使う
    vector< vector<vector<ll> > > dp(3, vector<vector<ll> >(N/2+5, vector<ll>(2, -1e18)));

    dp[0][0][0] = 0;
    dp[0][0][1] = 0;
    dp[1][0][0] = 0;
    dp[1][1][1] = A[1];

    FOR(i, 2, N) {
        FOR(j, (i-1)/2, (i+1)/2) {
            dp[i%2][j][0] = max(dp[(i-1)%2][j][0], dp[(i-1)%2][j][1]);
            if(j>=1)
                dp[i%2][j][1] = dp[(i-1)%2][j-1][0] + A[i];
        }
    }

    cout << max(dp[N%2][N/2][0], dp[N%2][N/2][1]) << endl;
    
    return 0;
}