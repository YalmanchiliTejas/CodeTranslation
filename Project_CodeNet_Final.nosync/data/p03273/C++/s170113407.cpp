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
// functions

#endif

void rotate_right(vs& r, vs& g){
    int H = g.size();
    int W = g[0].size();
    r = vs(W, string(H, ' '));

    REP(i,W){
        REP(j,H){
            r[i][j] = g[H - 1 - j][i];
        }
    }    
}

void rotate_left(vs& l, vs& g){
    int H = g.size();
    int W = g[0].size();
    l = vs(W, string(H, ' '));

    REP(i,W){
        REP(j,H){
            l[i][j] = g[j][W-1-i];
        }
    }    
}

int main_B() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int H, W; cin >> H >> W;
    vs g(H); REP(i, H) cin >> g[i];

    regex re("\\.+");
    vs t;
    REP(i,H) {
        if (regex_match(g[i], re)) continue;
        t.push_back(g[i]);
    }

    vs r;
    rotate_right(r, t);

    t.clear();
    REP(i,W) {
        if (regex_match(r[i], re)) continue;
        t.push_back(r[i]);
    }
    
    vs ans;
    rotate_left(ans, t);

    for(string s : ans){
        cout << s << endl;
    }

    return 0;
}