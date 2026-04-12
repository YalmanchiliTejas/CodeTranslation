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

llong get(llong action, llong l, llong r){
    if(dp[l][r][action] != -INF) return dp[l][r][action];
    if(l == r) {
        if(action == 1) return a[l];
        else return -a[l];
    }
    if(action == 1){
        llong choice1 = get(0, l + 1, r) + a[l];
        llong choice2 = get(0, l, r - 1) + a[r];
        return dp[l][r][1] = max(choice1, choice2);
    }else{
        llong choice1 = get(1, l + 1, r) - a[l];
        llong choice2 = get(1, l, r - 1) - a[r];
        return dp[l][r][0] = min(choice1, choice2);
    }
}

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
    }
    cout << get(1, 1, n);
}
