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
#define FOR(i, start, finish, k) for(int i = start; i <= finish; i += k)

const int MXN = 2e5 + 200;
const long long MNN = 2e3 + 200;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
const int OO = 1e9 + 500;

typedef long long llong;
typedef unsigned long long ullong;

using namespace std;

llong n, m, k, f[MXN];

llong binpow(llong a, llong b){
    if(b == 0) return 1;
    if(b % 2 == 1) return binpow(a, b - 1) * a % MOD;
    else{
        llong x = binpow(a, b / 2);
        return x * x % MOD;
    }
}

llong C(llong n, llong k){
    llong up = f[n];
    llong down = (f[k] * f[n - k]) % MOD;
    return (up * binpow(down, MOD - 2)) % MOD;
}

llong d() {
    llong num = m - 1;
    llong res_x = 0, res_y = 0;
    res_x = (num + 1) * (2 * num + 4) * num / 12 % MOD;
    res_x = res_x * n * n % MOD;
    num = n - 1;
    res_y = (num + 1) * (2 * num + 4) * num / 12 % MOD;
    res_y = res_y * m * m % MOD;
    return (res_x + res_y) % MOD;
}

int main () {
    ios;
    cin >> n >> m >> k;
    f[0] = 1;
    for(int i = 1; i <= n * m; i++){
        f[i] = (f[i - 1] * i) % MOD;
    }
    cout << (C(n * m - 2, k - 2) * d()) % MOD;
    return 0;
}
