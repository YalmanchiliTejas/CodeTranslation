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

llong n, b[MXN], ans;

int main () {
    ios;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    for(llong i = 1; i < n; i++){
        llong res = 0;
        if ((n - 1) % i == 0) {
            for (int j = 1, k = n; j < k; j += i, k -= i) {
                res+= b[j] + b[k];
                ans = max(ans, res);
            }
        } else {
            for (int j = 1, k = n; j < n && k > i; j += i, k -= i) {
                res += b[j] + b[k];
                ans = max(ans, res);
            }
        }
    }
    cout << ans;
    return 0;
}
