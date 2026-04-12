// O O O O O O O O O O O O O O O OO O OO O OO O O O TTCH O TTTCH O TTTCH O O O O
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx")
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stdio.h>
#include <cstdio>
#include <math.h>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
// #include <random>
#include <iomanip>
#include <bitset>
#include <cassert>
 
using namespace std;

#define y1 y11
#define double long double
#define less less228
#define left left228
#define right right228
#define list list228
#define all(v) v.begin(), v.end()
 
 
 
template<typename T> void uin(T &a, T b) {
    if (b < a) a = b;
}
template<typename T> void uax(T &a, T b) {
    if (b > a) a = b;
}

const int N = 100 * 1000 + 282;

bool dp[N][2];

vector<int>g[N];

void dfs(int v, int par = -1) {
    vector<int> sons;
    for (int to : g[v]) {
        if (to != par) {
            dfs(to, v);
            sons.emplace_back(to);
        }
    }
    int sz = (int)sons.size();
    dp[v][0] = 1;
    int good = 0;
    for (int to : sons) {
        if (!dp[to][1])dp[v][0]=0;
        if (dp[to][1])++good;
    }
    for (int to : sons) {
        if (good - dp[to][1] == sz - 1 && dp[to][0]) {
            dp[v][1] = 1;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    dfs(1);
    if (dp[1][1]) cout << "Second\n";
    else cout << "First\n";
    return 0;
}
// RU_023
 
/*
4 2
2 1 3 3
1 2 4 3
6 1 7 4
5 3 7 5

3 3
1 1 1 1
1 2 1 2
1 3 1 3

*/