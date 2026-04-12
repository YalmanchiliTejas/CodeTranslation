/*
    Author: Nguyen Tan Bao
    Status:
    Idea:
*/

#include <bits/stdc++.h>
#define FI first
#define SE second
#define EPS 1e-9
#define ALL(a) a.begin(),a.end()
#define SZ(a) int((a).size())
#define MS(s, n) memset(s, n, sizeof(s))
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORE(i,a,b) for (int i = (a); i >= (b); i--)
#define FORALL(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
//__builtin_ffs(x) return 1 + index of least significant 1-bit of x
//__builtin_clz(x) return number of leading zeros of x
//__builtin_ctz(x) return number of trailing zeros of x

using namespace std;
using ll = long long;
using ld = double;
typedef pair<int, int> II;
typedef pair<II, int> III;
typedef complex<ld> cd;
typedef vector<cd> vcd;

const ll MODBASE = 1000000007LL;
const int MAXN = 100010;
const int MAXM = 1000;
const int MAXK = 16;
const int MAXQ = 200010;

int pos[MAXN];
ll n, x, m, z[MAXN];
vector<ll> w;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> x >> m;
    pos[x] = 1;
    ll now = x;

    int idx = 1, cycleLen = 0, start = 0;
    z[1] = x;
    while (1) {
        idx++;
        now = now * now % m;
        if (pos[now] == 0) {
            pos[now] = idx;
            z[idx] = now;
        } else {
            cycleLen = idx - pos[now];
            start = pos[now];
            idx--;
            break;
        }
    }
    ll res = 0;
    if (n < start) {
        FOR(i,1,n) res += z[i];
        cout << res;
    }
    else {
        FOR(i,1,start-1) res += z[i];
        FOR(i,start,idx) w.push_back(z[i]);
        
        FOR(i,1,SZ(w)-1) w[i] += w[i-1];
        n -= start-1;
        
        ll numCycle = n / cycleLen;
        res += numCycle * w[SZ(w)-1];
        n %= cycleLen;
        if (n > 0) res += w[n-1];
        
        cout << res;
    }
    return 0;
}
