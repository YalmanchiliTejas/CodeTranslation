#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <memory>
#include <complex>
#include <numeric>
#include <cstdio>
#include <iomanip>
#include <random>

#define REP(i,m,n) for(int i=int(m);i<int(n);i++)
#define RREP(i,m,n) for(int i=int(n)-1;i>=int(m);--i)
#define EACH(i,c) for (auto &(i): c)
#define all(c) begin(c),end(c)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort(begin(c),end(c))
#define pb emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
//#define int long long

#ifdef LOCAL
#define DEBUG(s) cout << (s) << endl
#define dump(x)  cerr << #x << " = " << (x) << endl
#define BR cout << endl;
#else
#define DEBUG(s) do{}while(0)
#define dump(x) do{}while(0)
#define BR 
#endif
using namespace std;

using UI = unsigned int;
using UL = unsigned long;
using LL = long long;
using ULL = unsigned long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using VS = vector<string>;
using PII = pair<int,int>;
using VP = vector<PII>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

// constexpr double EPS = 1e-10;
//constexpr double PI  = acos(-1.0);
//constexpr int INF = INT_MAX;
// constexpr int MOD = 1'000'000'007;
//inline void modAdd(LL &l, LL &r) {l = (l + r) % MOD;}

template<class T> inline T sqr(T x) {return x*x;}

void solve() {
    LL n,x,m;
    cin >> n >> x >> m;
    LL a1 = sqr(x) % m;
    LL ans = x;
    --n;
    // n -= 631;
    if (n < m) {
        REP(i,0,n) {
            // dump(a1);
            ans = (ans + a1);
            a1 = sqr(a1) % m;
        }
        cout << ans << endl;
        return;
    }

    map<LL,int> ma;
    VLL ss;
    LL sum = 0;
    REP(i,0,m) {
        if (ma.count(a1) > 0) break;
        ma[a1] = i;
        sum = (sum + a1);
        ss.push_back(sum);
        if (a1 == 0) break;
        a1 = sqr(a1) % m;
    }
    if (a1 == 0) {
        cout << ans + sum << endl;
        return;

    }
    int len = ma.size() - ma[a1];
    // dump(ss[ma[a1]-1]);
    if (ma[a1] > 0) sum -= ss[ma[a1]-1];
    // --len;
    if (ma[a1] > 0) {
        ans += ss[ma[a1]-1];
        n -= ma[a1];
    }
    dump(len);
    dump(sum);
    sum = sum * (n / len);
    ans = (ans + sum);
    n %= len;
    dump(n);
    dump(ans);
    // if (n > 0) {
    //     ans += ss[n-1];
    //     cout << ans << endl;
    //     return;
    // }
    // a1 = sqr(x) % m;
    REP(i,0,n) {
        ans = (ans + a1);
        a1 = sqr(a1) % m;
    }
    cout << ans << endl;
}

signed main() {
    solve();
    
    return 0;
}