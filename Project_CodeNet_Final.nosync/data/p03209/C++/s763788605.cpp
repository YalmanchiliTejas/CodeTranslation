#ifdef _DEBUG
#include "MyLib.h"
#else
#define main_D main
#include "bits/stdc++.h" 
#include <regex>
#define _USE_MATH_DEFINES
#include <math.h>
#define FOR(i,s,e) for (int i = int(s); i < int(e); ++i)
#define REP(i,e) FOR(i,0,e)
#define INF (INT_MAX/2)
#define EPS (1.0e-8)
#define LINF (LLONG_MAX/2)
const int MGN = 8;
const int ARY_SZ_MAX = 10000000;
using namespace std;
using ll = long long; using ull = unsigned long long;
using vi = vector<int>; using vvi = vector<vi>; using vvvi = vector<vvi>;
using vb = vector<bool>; using vvb = vector<vb>; using vvvb = vector<vvb>;
using vl = vector<ll>; using vvl = vector<vl>;
using vd = vector<double>; using vs = vector<string>;
using pii = pair<int, int>; using pll = pair<ll, ll>;
using psi = pair<string, int>;
// functions

#endif 

vl all, pat;

ll rec(ll n, ll rem) {
    if (n == 0) return 1;

    // eat the bottom bun
    if (rem >= 1) rem--;

    ll res = 0;
    if (rem>=1) {
        // eat a n-1 burger
        if (rem >= all[n-1]) {
            rem -= all[n - 1];
            res += pat[n - 1];
        } else {
            res += rec(n - 1, rem);
            rem = 0;
        }
    }

    // eat the middle pat
    if (rem >= 1) {
        res++;
        rem--;
    }

    if (rem>=1) {
        // eat a n-1 burger
        if (rem >= all[n-1]) {
            rem -= all[n - 1];
            res += pat[n - 1];
        } else {
            res += rec(n - 1, rem);
            rem = 0;
        }
    }

    // eat the top bun
    if (rem >= 1) rem--;

    return res;
}

int main_D() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, X; cin >> N >> X;

    all = vl(N + 1, 0);
    pat = vl(N + 1, 0);
    all[0] = 1;
    pat[0] = 1;
    REP(i, N) {    
        all[i + 1] = all[i] * 2 + 3;
        pat[i + 1] = pat[i] * 2 + 1;
    }

    ll ans = rec(N, X);

    cout <<  ans << endl;
    all.clear();
    pat.clear();

    return 0;
}