//
//  main.cpp
//  atcoder-intervals-2
//
//  Created by r on 6/11/19.
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

typedef long long ll;


ll add(ll a, ll b) {
    a += b;
    if(a >= MOD) {
        a -= MOD;
    }
    return a;
}
ll sub(ll a, ll b) {
    a -= b;
    if(a < 0) {
        a += MOD;
    }
    return a;
}
void add_self(ll& a, ll b) {
    a = add(a, b);
}
void sub_self(ll& a, ll b) {
    a = sub(a, b);
}

const ll MAXN = 200010;

vector<pair<ll, ll>> intervals[MAXN];
ll N, M;
ll t[4*MAXN];
ll lazy[4*MAXN];
ll dp[MAXN];

void push(ll v) {
    t[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(ll v, ll tl, ll tr, ll l, ll r, ll addend) {
    if (l > r)
        return;
    if (l == tl && tr == r) {
        t[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        ll tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}

ll query(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r)
        return inf;
    if (l <= tl && tr <= r)
        return t[v];
    push(v);
    ll tm = (tl + tr) / 2;
    return min(query(v*2, tl, tm, l, min(r, tm)),
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    ll total = 0;
    cin >> N >> M;
    for (ll i = 2; i<=M+1; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a++;
        b++;
        intervals[b].push_back({a, c});
        total+=c;
    }
    
    for (int i = 2; i<=N+2; i++) {
        dp[i] = query(1, 1, N+2, 1, i-1);
        for (auto li:intervals[i]) {
            update(1, 1, N+2, 1, li.first-1, li.second);
        }
        update(1, 1, N+2, i, i, dp[i]);
    }
    cout << total-dp[N+2] << endl;
    return 0;
}



