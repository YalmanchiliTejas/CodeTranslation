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
#include <functional>
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<double> VD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

template<typename T> void chmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T &a, T b) { if (a < b) a = b; }

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }

const ll INF = 1e18;

int main(void){
    ll n;
    cin >> n;
    VL a(n);
    REP(i,n) a[i] = in();
    VVL dp(n + 1, VL(3, -INF));
    REP(i,3) dp[i][i] = a[i];
    REP(i,n) REP(j,3){
        if (dp[i][j] == -INF) continue;
        FOR(k,1,3){
            int d = i + k + 1;
            int p = j + k - 1;
            if (d >= n) continue;
            if (p >= 3) continue;
            chmax(dp[d][p], dp[i][j] + a[d]);
        }
    }
    ll ans = -INF;
    if (n % 2 == 0){
        chmax(ans, dp[n - 1][1]);
        chmax(ans, dp[n - 2][0]);
    }else{
        REP(j,3) chmax(ans, dp[n - 1 - j][2 - j]);
    }
    cout << ans << endl;
    return 0;
}
