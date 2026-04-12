#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <fstream>
#include <cassert>

using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)

#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()
#define pb push_back
#define mp make_pair
#define EPS 1e-7
#define Pi 3.14159265358979
#define FILL(a,v) memset(a,v,sizeof(a))

using namespace std;


typedef long long Long;
typedef unsigned long long ULong;
typedef unsigned int Uint;
typedef unsigned char Uchar;
typedef vector <int> VI;
typedef pair <int, int> PII;


const int M = 1000000007;
const int MAXN = 107;

Long binpow(Long b, int p) {
    Long res = 1;
    while (p > 0) {
        if (p&1)
            res *= b;
        b*=b;
        b%=M;
        res %= M;
        p >>= 1;
    }
    return res;
}


Long col(int h) {
    return binpow(2,h);
}
int n;

Long dps[MAXN];
Long dpd[MAXN];
Long dpc[MAXN][MAXN];


Long solve(VI h) {
    int n = h.size();
    if (n == 0)
        return 1;

    dps[0] = dpd[0] = (2*col(h[0]-2))%M;
    REP(i,n) {
        if (h[i] <= h[0])
            dpc[0][i] = (2*col(h[0]-h[i]))%M;
    }

    FOR(i,1,n) {
        dps[i] = dps[i-1]*col(h[i]-h[i-1])%M;
        dpd[i] = dpd[i-1]*col(h[i]-h[i-1])%M;
        if (h[i] <= h[i-1])
            dpd[i] += dpc[i-1][i];
        else
            dpd[i] += dpc[i-1][i-1]*col(h[i]-h[i-1])%M;
        dps[i] %= M;
        dpd[i] %= M;


        FOR(j, i, n) {
            if (h[j] > h[i])
                continue;

            if (h[j] >= h[i-1]) {
                dpc[i][j] = 2*dpc[i-1][i-1]*col(h[i]-h[j]);
                continue;
            }

            if (h[i] >= h[i-1])
                dpc[i][j] = (dpc[i-1][j] + dpc[i-1][i-1])*col(h[i] - h[i-1]);
            else {
                dpc[i][j] = dpc[i-1][j] + dpc[i-1][i];
            }
        }
        REP(j,n)
            dpc[i][j] %= M;

    }
//
//    REP(i,n) {
//        cout << dps[i] << "\t" << dpd[i] << "\t";
//        REP(j,n)
//            cout << dpc[i][j] << "\t";
//        cout << endl;
//    }

//    cout << dps[n-1] + dpd[n-1] << endl;

    return (dps[n-1] + dpd[n-1])%M;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    Long res = 1;

    int t;
    VI h;


    REP(i,n) {
        cin >> t;
        if (t == 1) {
            res *= solve(h);
            res %= M;
            res *= 2;
            res %= M;
            h.clear();
        } else {
            h.pb(t);
        }
    }

    res *= solve(h);

    cout << res%M << endl;

    return 0;
}