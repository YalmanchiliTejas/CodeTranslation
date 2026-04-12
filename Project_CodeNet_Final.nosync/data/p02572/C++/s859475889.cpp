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

//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
//#pragma GCC optimmize("unroll-loops")

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
#define no {cout << "-1\n"; return;}

const int MOD = 1e9 + 7, rev2 = 500000004;

void solve() {
    int n; cin >> n;
    vector <int> a(n);
    int sum = 0;
    loop(i, n) {
        cin >> a[i];
        sum = (sum + a[i]) % MOD;
    }
    sum = sum * sum % MOD;
    loop(i, n)
        sum = (sum - a[i] * a[i] % MOD + MOD) % MOD;
    cout << sum * rev2 % MOD;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //int t; cin >> t; loop(i, t)
    solve();
    return 0;
}