#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <random>
#include <cassert>
#include <cstring>
using namespace std;

#define GET_ARG(a,b,c,F,...) F
#define REP3(i,s,e) for (i = s; i <= e; i++)
#define REP2(i,n) REP3 (i,0,(int)(n)-1)
#define REP(...) GET_ARG (__VA_ARGS__,REP3,REP2) (__VA_ARGS__)
#define RREP3(i,s,e) for (i = s; i >= e; i--)
#define RREP2(i,n) RREP3 (i,(int)(n)-1,0)
#define RREP(...) GET_ARG (__VA_ARGS__,RREP3,RREP2) (__VA_ARGS__)
#define DEBUG(x) cerr << #x ": " << x << endl

typedef long long ll;

ll a[50];

int main(void) {
    int i, j, n;
    cin >> n;
    REP (i,n) cin >> a[i];

    ll ans = 0;
    bool found = true;
    while (found) {
        found = false;
        REP (i,n) if (a[i] >= n) {
            long long x = a[i] / n;
            REP (j,n) if (j != i) a[j] += x;
            a[i] %= n;
            ans += x;
            found = true;
        }
    }
    cout << ans << endl;
    return 0;
}