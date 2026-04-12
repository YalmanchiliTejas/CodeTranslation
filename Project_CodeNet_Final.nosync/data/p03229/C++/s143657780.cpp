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
// functions
bool second_greater(const pii& left, const pii& right) {
    return left.second > right.second;
}
#endif


int main_C() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;  cin >> N;
    vi A(N); REP(i, N) cin >> A[i];

    sort(A.begin(), A.end());

    ll ans = 0;
    vi p;
    if (N%2==1) {
        // (i) updown
        p.push_back(-1);
        p.push_back(-1);
        for(int i=1; i<N-1; i++) {
            if (i % 2 == 0) p.push_back(-2);
            else p.push_back(2);
        }
        sort(p.begin(), p.end());
        ll sum = 0;
        REP(i, N) sum += p[i] * A[i];

        ans = max(ans, sum);

        // (ii) downup
        p.clear();
        p.push_back(1);
        p.push_back(1);
        for(int i=1; i<N-1; i++) {
            if (i % 2 == 1) p.push_back(-2);
            else p.push_back(2);
        }
        sort(p.begin(), p.end());
        sum = 0;
        REP(i, N) sum += p[i] * A[i];

        ans = max(ans, sum);
    } else {
        // (i) updown
        p.push_back(-1);
        p.push_back(1);
        for(int i=1; i<N-1; i++) {
            if (i % 2 == 0) p.push_back(-2);
            else p.push_back(2);
        }
        sort(p.begin(), p.end());
        ll sum = 0;
        REP(i, N) sum += p[i] * A[i];

        ans = max(ans, sum);

        // (ii) downup
        p.clear();
        p.push_back(1);
        p.push_back(-1);
        for(int i=1; i<N-1; i++) {
            if (i % 2 == 1) p.push_back(-2);
            else p.push_back(2);
        }
        sort(p.begin(), p.end());
        sum = 0;
        REP(i, N) sum += p[i] * A[i];

        ans = max(ans, sum);
    }

    cout << ans << endl;

    return 0;
}