#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set> 
#include <map>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <cctype>
#define REP(i,n) for(int i=0; i<(n); ++i)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const ll INFLL = 1001001001001001001;  // > 10^18
const int MOD = (int)1e9 + 7;
const ll MODLL = (ll)1e9 + 7;
const double EPS = 1e-9;



int main () {

    int n,m; cin >>n>>m;
    vector<vector<bool> > adj(n, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
        int v; cin >> v; --v;
        int u; cin >> u; --u;
        adj[v][u] = true;
        adj[u][v] = true;
    }

    vector<vector<ll> > dp(1<<n, vector<ll>(n, 0));
    dp[1][0] = 1;

    for(int bit = 0; bit < (1<<n)-1; bit++){
        for(int k = 0; k < n; k++){
            for(int j = 0; j < n; j++){
                if(!(bit & (1 << k)) && (bit & (1 << j)) && adj[j][k]) {
                    dp[bit | (1<<k)][k] += dp[bit][j];
                }
            } 
        }
    }

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += dp[(1<<n) - 1][i];
    }
    cout << sum << endl;

    return 0;
}


