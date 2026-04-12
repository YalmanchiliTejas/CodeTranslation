//#include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <utility>
#include <climits>
#define REP(i, n) for(int i = 0; i < n; ++i)
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define F first
#define S second
#define OUT(x) cout << (x) << "\n"
using namespace std;
using point = pair< int,int >;
using ll = long long;

int main() {
    int r, g, b;
    cin >> r >> g >> b;

    int sum = r * 100 + g * 10 + b;

    OUT(sum % 4 == 0 ? "YES" : "NO");
    return 0;
}

