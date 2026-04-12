//
//  main.cpp
//  atcoder-deque
//
//  Created by r on 6/1/19.
//  Copyright © 2019 r. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>
#include <assert.h>
#include <limits>
#include <cstdio>
using namespace std;

//#define RDEBUG 1
#ifdef RDEBUG
#define D(x) x
#else
#define D(x)
#endif
#define inf 0x7fffffff
#define MOD 1000000007

long long N;
long long a[3010];
long long dp[3010][3010][2];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (long long i = 0; i<N; i++) {
        cin >> a[i];
    }
    for (long long i = N-1; i>=0; i--) {
        for (long long j = i; j<N; j++) {
            dp[i][j][0] = max(a[i]+dp[i+1][j][1], a[j]+dp[i][j-1][1]);
            dp[i][j][1] = min(dp[i+1][j][0]-a[i], dp[i][j-1][0]-a[j]);
        }
    }
    cout << dp[0][N-1][0] << endl;
    return 0;
}



