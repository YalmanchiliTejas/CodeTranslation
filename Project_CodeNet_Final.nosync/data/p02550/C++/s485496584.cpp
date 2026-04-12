#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <numeric>
#include <ctime>
#include <complex>
#include <bitset>
#include <random>
#include <stack>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll
#define double ld
#define loop(i, n) for(int i = 0; i < (int)n; ++i)
#define loop1(i, n) for(int i = 1; i <= (int)n; ++i)
#define F first
#define S second
#define pb push_back
#define pi pair <int, int>
#define all(x) begin(x), end(x)
#define ti tuple <int, int, int>
#define Point Vect
#define mkt make_tuple
#define mkp make_pair
#define no {cout << "-1\n"; return;}

void solve() {
    int n, x, m, ans = 0;
    cin >> n >> x >> m;
    if (n <= m) {
        loop(i, n) {
            ans += x;
            x = x * x % m;
        }
    }
    else {
        map <int, int> was;
        int cnt = 0, fst = x;
        while (was.find(x) == was.end()) {
            was[x] = cnt++;
            x = x * x % m;
        }
        int len = cnt - was[x];
        int pos = was[x];
        n -= pos;
        loop(i, pos) {
            ans += fst;
            fst = fst * fst % m;
        }
        int cycle = 0;
        do {
            cycle += fst;
            fst = fst * fst % m;
        } while (fst != x);
        ans += n / len * cycle;
        n %= len;
        loop(i, n) {
            ans += x;
            x = x * x % m;
        }
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //int t; cin >> t; loop(i, t)
    solve();
    return 0;
}