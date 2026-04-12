#pragma GCC optimize("O3")
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
using namespace std;

using ll = long long;
using P = pair<int, int>;

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr long long INF = 1e18;
constexpr double pi = acos(-1);
constexpr double EPS = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

// dp[i][j][tight] := i 桁目, mod D = j, 未満フラグ tight
ll dp[10010][110][2];

string k;
int d;

ll rec(int i, int j, int tight){
    
    if(i == k.size()){
        return j == 0;
    }

    int num = k[i] - '0';

    int lim = tight ? 9 : num;

    ll &res = dp[i][j][tight];

    if(~res) return res;

    res = 0;

    for(int x=0; x<=lim; x++){
        res += rec(i + 1, (j + x) % d, tight || (x < lim));
        res %= MOD;
    }

    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>k>>d;

    memset(dp, -1, sizeof(dp));

    ll ans = rec(0, 0, 0) - 1 + MOD;

    cout << ans % MOD << endl;
}