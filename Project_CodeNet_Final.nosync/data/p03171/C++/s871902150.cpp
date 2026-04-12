//
//  ROIGold.cpp
//  Main calisma
//
//  Created by Rakhman on 05/02/2019.
//  Copyright © 2019 Rakhman. All rights reserved.
//

#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iterator>

#define ios ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
#define S second
#define F first
#define pb push_back
#define nl '\n'
#define NL cout << '\n';
#define EX exit(0)
#define all(s) s.begin(), s.end()
#define no_answer return cout << "NO", 0;
#define FOR(i, start, finish, k) for(int i = start; i <= finish; i += k)

const int MXN = 4e5 + 200;
const long long MNN = 3e3 + 200;
const long long MOD = 1e9 + 7;
const long long INF = 1e13;
const int OO = 1e9 + 500;

typedef long long llong;
typedef unsigned long long ullong;

using namespace std;

int n, k, a[MXN];
llong dp[MNN][MNN][2];

int main () {
    ios;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            dp[i][j][0] = dp[i][j][1] = -INF;
        }
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        dp[i][i][1] = a[i];
        dp[i][i][0] = -a[i];
    }
    for(int sz = 1; sz <= n - 1; sz++){
        for(int l = 1; l + sz <= n; l++){
            int r = l + sz;
            dp[l][r][0] = min(dp[l][r - 1][1] - a[r], dp[l + 1][r][1] - a[l]);
            dp[l][r][1] = max(dp[l][r - 1][0] + a[r], dp[l + 1][r][0] + a[l]);
        }
    }
    cout << dp[1][n][1];
}
