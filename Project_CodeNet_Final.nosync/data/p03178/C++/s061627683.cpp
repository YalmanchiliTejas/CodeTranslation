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
#define no_answer return cout << 0, 0;
#define FOR(i, start, finish, k) for(llong i = start; i <= finish; i += k)
 
const long long MXN = 136 + 200;
const long long MNN = 1e4 + 520;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
const long long OO = 1e9 + 500;
 
typedef long long llong;
typedef unsigned long long ullong;
 
using namespace std;

string k;
llong d;

int main () {
    ios;
    cin >> k >> d;
    vector<vector<llong> > dp(d, vector<llong> (2, 0));
    dp[0][0] = 1;
    for(int i = 0; i < k.size(); i++){
        vector<vector<llong> > new_dp(d, vector<llong> (2, 0));
        for(int sum = 0; sum < d; sum++){
            for(int lol = 0; lol <= 1; lol++){
                for(int j = 0; j < 10; j++){
                    if(j > k[i] - '0' && lol == 0){
                        break;
                    }
                    new_dp[(sum + j) % d][lol || (j < k[i] - '0')] = (new_dp[(sum + j) % d][lol || (j < k[i] - '0')] + dp[sum][lol]) % MOD;
                }
            }
        }
        dp = new_dp;
    }
    llong ans = dp[0][0] + dp[0][1];
    cout << (ans + MOD - 1) % MOD;
}
