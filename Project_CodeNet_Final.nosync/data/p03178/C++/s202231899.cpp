#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <bitset>
#include <stack>


using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)





string n;
ll d;
ll dp[10005][2][105];

ll rec(ll k, bool tight, ll sum){
    if(k == n.size()) return sum == 0;
    
    ll x = n[k] - '0';
    ll r = tight? x : 9;
    
    ll &res = dp[k][tight][sum];
    if(~res) return res;
    res = 0;
    
    for(ll i = 0; i <= r; i++){
        res += rec(k + 1, tight && i == r, (sum + i) % d);
        res %= MOD;
    }
    
    return res;
}

int main() {
    cin >> n >> d;
    memset(dp, -1, sizeof(dp));
    cout << (rec(0, true, 0) - 1 + MOD) % MOD << endl;
}
