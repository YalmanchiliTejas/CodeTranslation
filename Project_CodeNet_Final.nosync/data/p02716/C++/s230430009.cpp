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
#include <assert.h>
#include <unordered_set>
#include <random>


using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)

















int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    REP(i, n){
        cin >> a[i];
    }
    if(n % 2 == 0){
        vector dp(n + 5, vector(2, -INF));
        dp[0][0] = 0;
        REP(i, n){
            dp[i + 2][0] = max(dp[i + 2][0], dp[i][0] + a[i]);
            dp[i + 1][1] = max(dp[i + 1][1], dp[i][0]);
            dp[i + 2][1] = max(dp[i + 2][1], dp[i][1] + a[i]);
        }
        ll ans = max({dp[n][0], dp[n][1], dp[n + 1][0], dp[n + 1][1]});
        cout << ans << endl;
    }
    else{
        vector dp(n + 5, vector(3, -INF));
        dp[0][0] = 0;
        REP(i, n){
            dp[i + 2][0] = max(dp[i + 2][0], dp[i][0] + a[i]);
            dp[i + 1][1] = max(dp[i + 1][1], dp[i][0]);
            dp[i + 2][1] = max(dp[i + 2][1], dp[i][1] + a[i]);
            dp[i + 1][2] = max(dp[i + 1][2], dp[i][1]);
            dp[i + 2][2] = max(dp[i + 2][2], dp[i][2] + a[i]);
        }
        ll ans = max({dp[n][0], dp[n + 1][0], dp[n][1], dp[n + 1][1], dp[n][2], dp[n + 1][2]});
        cout << ans << endl;
    }
}