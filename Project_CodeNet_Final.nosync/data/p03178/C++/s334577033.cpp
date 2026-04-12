#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }

const ll mod = 1e9 + 7;
ll dp[100003][102][2];

int main() {
    string s;
    int d;
    cin >> s >> d;
    int n = s.length();
    dp[0][0][0] = 1;
    REP(i,n) REP(j,d) REP(f,2){
        int y = s[i] - '0';
        int lim = f ? 9 : y;
        FOR(x,0,lim){
            (dp[i+1][(j+x)%d][f|(x<y)] += dp[i][j][f]) %= mod;
        }
    }
    ll ans = mod - 1;
    REP(f,2) ans = (ans + dp[n][0][f]) % mod;
    cout << ans << endl;
    return 0;
}
