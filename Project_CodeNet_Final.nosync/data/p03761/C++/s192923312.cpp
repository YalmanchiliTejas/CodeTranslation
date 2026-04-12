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
using psi = pair<string, int>;
// functions

#endif


int main_C() {
    cin.tie(0);
    ios::sync_with_stdio(false);


    int N; cin >> N;
    vs S(N); REP(i, N) cin >> S[i];

    vi h(26, INF);
    REP(i,N) {
        map<char, int> mp;
        for(char c : S[i]) {
            mp[c]++;
        }
        for(char c = 'a'; c<= 'z'; c++) {
            h[c - 'a'] = min(h[c - 'a'], mp[c]);
        }
    }

    string ans = "";
    for(char c = 'a'; c<= 'z'; c++) {
        if (h[c - 'a'] >= INF) continue;
        ans += string(h[c - 'a'], c);
    }

    cout <<  ans << endl;

    return 0;
}