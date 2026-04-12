#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <string.h>
#include <cmath>
#include <math.h>
#include <iterator>
#include <iomanip>
#include <set>
#include <bitset>
#include <algorithm>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <cctype>
#include <ctime>
#include <climits>
#include <limits>
#define fore(i,a,b) for(ll i = (a),_b = (b); i < (_b); i++)
#define fort(i,a,b) for(ll i = (a),_b = (b); i <= (_b); i++)
#define ford(i,a,b) for(ll i = (a),_b = (b); i >= (_b); i--)
#define fi first
#define se second
#define sz(x) ((ll)(x).size())
#define pb push_back
#define pf push_front
//#define LOCAL
using namespace std;

typedef long long ll;

const ll maxD = 1e2 + 5;
const ll maxN = 1e4 + 5;
const ll MOD = 1e9 + 7;

ll d,n;
ll dp[maxN][maxD][2];
bool vis[maxN][maxD][2];
string k;

void input(){
    cin >> k >> d;
    n = sz(k);
}

ll DP(const ll idx,
      const ll tot,
      const bool all){
    if(idx >= n)
        return !tot;
    if(!vis[idx][tot][all]){
        vis[idx][tot][all] = true;
        const int x = all ? 9 : (k[idx] - '0');
        fort(i,0,x)
            dp[idx][tot][all] = (dp[idx][tot][all] + DP(idx + 1,(tot + i) % d,(i < x) || all)) % MOD;
    }
    return dp[idx][tot][all];
}

int main(){
    #ifdef LOCAL
        freopen("s.INP","r",stdin);
    #endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    cout << (DP(0,0,false) - 1 + MOD) % MOD << '\n';
    return 0;
}
