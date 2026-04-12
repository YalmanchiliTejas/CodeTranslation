#ifdef _DEBUG
#include "MyLib.h"
#else
#define main_E main
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
// functions

#endif


int main_E() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;  cin >> N;
    vi A(N);
    REP(i, N) cin >> A[i];
    
    deque<int> dq;
    REP(i,N) {
        int j = lower_bound(dq.begin(), dq.end(), A[i]) - dq.begin();
        if (j == 0) dq.push_front(A[i]);
        else dq[j - 1] = A[i];
    }

    int ans = dq.size();
    cout << ans << endl;

    return 0;
}