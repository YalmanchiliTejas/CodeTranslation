//
//  main.cpp
//  atcoder - digitsum
//
//  Created by r on 6/5/19.
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

long long add(long long a, long long b) {
    a += b;
    if(a >= MOD) {
        a -= MOD;
    }
    return a;
}
long long sub(long long a, long long b) {
    a -= b;
    if(a < 0) {
        a += MOD;
    }
    return a;
}
void add_self(long long& a, long long b) {
    a = add(a, b);
}
void sub_self(long long& a, long long b) {
    a = sub(a, b);
}

long long dp[10010][110][2];
string digits;
long long N = 0;
long long D;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> digits >> D;
    dp[digits.length()][0][0] = 1;
    dp[digits.length()][0][1] = 1;
    for (long long i = digits.length()-1; i>=0; i--) {
        for (long long j = 0; j<D; j++) {
            for (long long k = 0; k<digits[i]-'0'; k++) {
                add_self(dp[i][j][0], dp[i+1][j+k>=D ? (j+k)%D : j+k][1]);
                add_self(dp[i][j][1], dp[i+1][j+k>=D ? (j+k)%D : j+k][1]);
            }
            add_self(dp[i][j][0], dp[i+1][j+(digits[i]-'0')>=D ? (j+(digits[i]-'0'))%D : j+(digits[i]-'0')][0]);
            for (long long k = digits[i]-'0'; k<10; k++) {
                add_self(dp[i][j][1], dp[i+1][j+k>=D ? (j+k)%D : j+k][1]);
            }
        }
    }
    cout << sub(dp[0][0][0], 1LL) << endl;
    return 0;
}



