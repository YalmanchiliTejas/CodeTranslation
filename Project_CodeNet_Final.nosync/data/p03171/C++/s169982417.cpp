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







int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    REP(i, n){
        cin >> a[i];
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, -INF));
    REP(i, n + 1){
        dp[i][i] = 0;
    }
    for(ll i = 1; i <= n; i++){
        for(ll j = 0; j <= n - i; j++){
            dp[j][i + j] = -max(dp[j][i + j - 1] + a[j + i - 1], dp[j + 1][i + j] + a[j]);
        }
    }
    cout << -dp[0][n] << endl;
}