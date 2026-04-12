#ifdef _DEBUG
#include "MyLib.h"
#else
#define main_B main
#include "bits/stdc++.h" 
#include <regex>
#define _USE_MATH_DEFINES
#include <math.h>
#define FOR(i,s,e) for (int i = int(s); i < int(e); ++i)
#define REP(i,e) FOR(i,0,e)
#define INF (INT_MAX/2)
#define EPS (1.0e-8)
#define LINF (LONG_MAX/2)
const int MGN = 8;
const int ARY_SZ_MAX = 10000000;
using namespace std;
using ll = long long; using ull = unsigned long long;
using vi = vector<int>; using vvi = vector<vi>; using vvvi = vector<vvi>;
using vb = vector<bool>; using vvb = vector<vb>; using vvvb = vector<vvb>;
using vl = vector<ll>; using vvl = vector<vl>;
using vd = vector<double>; using vs = vector<string>;
using pii = pair<int, int>; using pll = pair<ll, ll>;
#endif

#ifdef _DEBUG
void init_global_B() {}
#else

#endif

int main_B() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int X, Y, Z; cin >> X >> Y >> Z;
    
    int ans = 0;
    REP(i,100001) {
        if (Y*i+Z*(i+1) > X) {
            ans = i - 1;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}