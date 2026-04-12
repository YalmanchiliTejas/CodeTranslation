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

vl a, p;

ll rec(ll n, ll x) {
    if (n == 0) return 1;

    assert(n >= 1);
    if (x == 1) { // B
        return 0;
    } else if (x <= 1 + a[n - 1]) { // B(n-1)
        return rec(n - 1, x - 1); 
    } else if (x == 1 + a[n - 1] + 1) { // B(n-1)P
        return p[n - 1] + 1;
    } else if (x <= 1 + a[n - 1] + 1 + a[n - 1]) { // B(n-1)P(n-1)
        return p[n - 1] + 1 + rec(n - 1, x - (a[n-1]+2));
    } else { // B(n-1)P(n-1)B
        return p[n - 1] * 2 + 1; 
    }
}

int main_D() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, X; cin >> N >> X;

    //vs L(N+1);
    a = vl(N + 1, 0);
    p = vl(N + 1, 0);
    //L[0] = "P";
    a[0] = 1;
    p[0] = 1;
    REP(i, N) {    
        //L[i + 1] = "B" + L[i] + "P" + L[i] + "B";
        //a[i + 1] = L[i + 1].size();
        a[i + 1] = a[i] * 2 + 3;
        p[i + 1] = p[i] * 2 + 1;
    }

    assert(N >= 1);
    assert(X >= 1);
    ll ans = rec(N, X);

    cout <<  ans << endl;
    a.clear();
    p.clear();

    return 0;
}