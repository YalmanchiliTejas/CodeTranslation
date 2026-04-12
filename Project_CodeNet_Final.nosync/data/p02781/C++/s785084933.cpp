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















string s;
ll k;
ll dp[1000][2][5];

ll rec(ll idx = 0, bool tight = true, ll cnt = 0){
    if(cnt > k) return 0;
    
    if(idx == s.size()){
        return cnt == k;
    }
    
    ll x = s[idx] - '0';
    ll r = tight? x : 9;
    
    ll &res = dp[idx][tight][cnt];
    if(~res) return res;
    res = 0;
    
    for(ll i = 0; i <= r; i++){
        res += rec(idx + 1, tight && (i == r), (i == 0? cnt : cnt + 1));
    }
    
    return res;
}

int main(){
    cin >> s >> k;
    memset(dp, -1, sizeof(dp));
    cout << rec() << endl;
}