#ifdef _DEBUG
#include "MyLib.h"
#else
#define main_C main
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


int main_C() {
    std::cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B, C, X, Y; 
    cin >> A >> B >> C >> X >> Y;

    int ans = 0;
    if (A+B <= C*2) {
        ans = A * X + B * Y;
    } else {
        if (X <= Y) {
            ans = min(C * X * 2 + B * (Y - X), C * Y * 2);
        } else {
            ans = min(C * Y * 2 + A * (X - Y), C * X * 2);
        }
    }

    cout << ans << endl;

    return 0;
}