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

const int MXN = 2e5 + 1;
const long long MNN = 5e3 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
const int OO = 1e9 + 500;

typedef long long llong;
typedef unsigned long long ullong;

using namespace std;

llong n, p[MXN], ans;
vector<pair<int, pair<int, int> > > q;

struct point{
    int x, y, ind;
}a[MXN];

bool cmp(point a, point b){
    return a.x < b.x;
}

bool cmp2(point a, point b){
    return a.y < b.y;
}

int batya(int x){
    if(p[x] == x){
        return x;
    }
    return batya(p[x]);
}


int main () {
    srand(time(0));
    cin >> n;
    for(int i = 1; i <= n; i++){
        p[i] = i;
        cin >> a[i].x >> a[i].y;
        a[i].ind = i;
    }
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i < n; i++){
        q.pb({a[i + 1].x - a[i].x, {a[i + 1].ind, a[i].ind}});
    }
    sort(a + 1, a + n + 1, cmp2);
    for(int i = 1; i < n; i++){
        q.pb({a[i + 1].y - a[i].y, {a[i + 1].ind, a[i].ind}});
    }
    sort(q.begin(), q.end());
    for(int i = 0; i < q.size(); i++){
        int c = q[i].F, u = q[i].S.F, v = q[i].S.S;
        int uBatya = batya(u);
        int vBatya = batya(v);
        if(uBatya == vBatya){
            continue;
        }else{
            if(rand() % 2 == 1){
                p[uBatya] = vBatya;
                p[v] = vBatya;
                p[u] = vBatya;
            }else{
                p[vBatya] = uBatya;
                p[v] = uBatya;
                p[u] = uBatya;
            }
            ans += c;
        }
    }
    cout << ans;
    return 0;
}
