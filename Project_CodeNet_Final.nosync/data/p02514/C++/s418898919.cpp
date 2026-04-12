#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <numeric>
#include <algorithm>
using namespace std;
#ifdef DEBUGRUN
#define LOG(a) (cerr<<__LINE__<<": "#a" = "<<(a)<<endl)
#define DBG(...) (__VA_ARGS__)
#else
#define LOG(...) ((void)0)
#define DBG(...) ((void)0)
#endif
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef long long Int;
#define INF (MY_INFINITY)
#define MOD (YOUR_MODULUS)

struct unionset {
    int ud[128];
    void init() { memset(ud, -1, sizeof(ud)); }
    int root(int x) { return ud[x]<0 ? x : ud[x]=root(ud[x]); }
    int size(int x) { return -ud[root(x)]; }
    bool same(int x, int y) { return root(x)==root(y); }
    bool set(int x, int y) {
        x=root(x); y=root(y);
        if(x!=y) {
            if(ud[y]<ud[x]) std::swap(x, y);
            ud[x]+=ud[y]; ud[y]=x;
        }
        return x!=y;
    }
} us;

int n, m, x[100], y[100];
Int c[100];

Int solve() {
    us.init();
    rep(k, m) us.set(x[k], y[k]);
    if(us.size(0)<n) return 0;
    Int ans = 1LL<<62;
    rep(i, m) {
        us.init();
        rep(k, m) if(i!=k) us.set(x[k], y[k]);
        if(us.size(0)<n) ans = min(ans, (Int)c[i]);
    }
    rep(i, m) rep(j, m) {
        us.init();
        rep(k, m) if(i!=k && j!=k) us.set(x[k], y[k]);
        if(us.size(0)<n) ans = min(ans, (Int)c[i]+c[j]);
    }
    return ans;
}

int main() {
    for(;;) {
        cin >> n >> m;
        if(n==0) return 0;
        rep(i, m) cin >> x[i] >> y[i] >> c[i];
        Int dz = 0;
        const int z = m;
        m = 0;
        rep(i, z) {
            if(c[i]>0) {
                x[m] = x[i];
                y[m] = y[i];
                c[m] = c[i];
                m++;
            }
            else {
                dz += c[i];
            }
        }
        cout << solve()+dz << endl;
    }
}