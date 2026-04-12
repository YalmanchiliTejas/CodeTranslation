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
#define LINF (LLONG_MAX/2)
const int MGN = 10;
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


int main_B() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W; cin >> H >> W;
    vs A(H); REP(i, H) cin >> A[i];

    vb row(H, false);
    REP(i,H){
        REP(j,W){
            if (A[i][j]=='#') {
                row[i] = true;
                break;
            }
        }
    }

    vb col(W, false);
    REP(j,W){
        REP(i,H){
            if (A[i][j]=='#') {
                col[j] = true;
                break;
            }
        }
    }

    REP(i,H){
        if (!row[i]) continue;
        REP(j,W){
            if (!col[j]) continue;
            cout << A[i][j];
        }
        cout << endl;
    }

    return 0;
}