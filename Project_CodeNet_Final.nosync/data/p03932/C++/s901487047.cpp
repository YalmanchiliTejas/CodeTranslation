#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <vector>
#include <complex>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <bitset>
#include <ctime>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cassert>
#include <cstddef>
#include <iomanip>
#include <numeric>
#include <tuple>
#include <sstream>
#include <fstream>
#include <chrono>
#include <random>

using namespace std;
#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define RREP(i, a) for(int (i) = (a) - 1; (i) >= 0; (i)--)
#define FORR(i, a, b) for(int (i) = (a) - 1; (i) >= (b); (i)--)
#define DEBUG(C) cerr << #C << " = " << C << endl;
using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<LL>;
using VVL = vector<VL>;
using VD = vector<double>;
using VVD = vector<VD>;
using PII = pair<int, int>;
using PDD = pair<double, double>;
using PLL = pair<LL, LL>;
using VPII = vector<PII>;
template<typename T> using VT = vector<T>;
#define ALL(a) begin((a)), end((a))
#define RALL(a) rbegin((a)), rend((a))
#define SORT(a) sort(ALL((a)))
#define RSORT(a) sort(RALL((a)))
#define REVERSE(a) reverse(ALL((a)))
#define MP make_pair
#define FORE(a, b) for (auto &&a : (b))
#define FIND(s, e) ((s).find(e) != (s).end())
#define EB emplace_back

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

const int MAX_H = 210;
const int MAX_W = 210;
int H, W;
VVI a;

LL dp[MAX_H][MAX_H][MAX_H + MAX_W];
//dp[eh][sh][eh + ew]; sw = (eh + ew) - sh;
//eh + ew == sh + sw

bool inside(int h, int w) {
    return 0 <= h && h < H && 0 <= w && w < W;
}

int main(void) {
    scanf("%d%d", &H, &W);
    a.resize(H, VI(W));
    //dp.resize(H, VVI(W, VI(H + W, 0));
    for_each(ALL(a), [](auto &v) {
        for_each(ALL(v), [](int &e){scanf("%d", &e);});
    });
    dp[0][0][0] = a[0][0];
    REP(i, MAX_H)REP(j, MAX_W)REP(k, MAX_H + MAX_W) dp[i][j][k] = 0;
    REP(eh, H) REP(sh, H) REP(ehw, H + W) {
        int ew = ehw - eh;
        int sw = ehw - sh;
        if (ew < 0 || sw < 0) continue;
        //cout << eh << " " << ew << " " << sh << " " << sw << endl;
        LL buf = 0;
        {
            
            if (inside(eh - 1, ew) && inside(sh - 1, sw)) {
                buf = max(buf, dp[eh - 1][sh - 1][ehw - 1]);
                //cout << eh - 1 << " " << sh - 1 << " " << ehw - 1 << endl;
            }
            if (inside(eh - 1, ew) && inside(sh, sw - 1)) {
                buf = max(buf, dp[eh - 1][sh][ehw - 1]);
                //cout << eh - 1 << " " << sh << " " << ehw - 1 << endl;
            }
            if (inside(eh, ew - 1) && inside(sh - 1, sw)) {
                buf = max(buf, dp[eh][sh - 1][ehw - 1]);
                //cout << eh << " " << sh - 1 << " " << ehw - 1 << endl;
            }
            if (inside(eh, ew - 1) && inside(sh, sw - 1)) {
                buf = max(buf, dp[eh][sh][ehw - 1]);
                //cout << eh << " " << sh << " " << ehw - 1 << endl;
            }
        }
        if (eh == sh && ew == sw) dp[eh][sh][ehw] = buf + a[eh][ew];
        else dp[eh][sh][ehw] = buf + a[eh][ew] + a[sh][sw];
        
    }
    cout << dp[H - 1][H - 1][H + W - 2] << endl;
}
