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

ll dp[110][5][2];

int main(void){
    string s;
    int k;
    cin >> s >> k;
    int n = s.length();
    dp[0][0][0] = 1;
    REP(i,n) REP(j,k+1) REP(f,2){
        int lim = f ? 9 : (s[i] - '0');
        FOR(x,0,lim){
            dp[i + 1][j + (x != 0)][f | (x < (s[i] - '0'))] += dp[i][j][f];
        }
    }
    ll ans = dp[n][k][0] + dp[n][k][1];
    cout << ans << endl;

    return 0;
}
