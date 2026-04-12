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

constexpr int MOD = 1'000'000'007;
//inline void modAdd(LL &l, LL &r) {l = (l + r) % MOD;}

long long power(long long x, long long n, long long mod = 1000000007) {
    if (n == 0) return 1;
    if (n % 2 == 0) return power(x * x % mod, n/2, mod);
    else return x * power(x, n-1, mod) % mod;
}

// 1 <= k <= n <= 10^7
#define CNKMAX 300001
class CNK1 {
    std::vector<long long> fac, finv, inv;
    int MOD;
public:
    CNK1(int mod = 1000000007): MOD(mod), fac(CNKMAX), finv(CNKMAX), inv(CNKMAX) {
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i < CNKMAX; i++){
            fac[i] = fac[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
            finv[i] = finv[i - 1] * inv[i] % MOD;
        }
    }
    int get(const int &n, const int &k) const {
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
    }
};

void solve() {
    int n,m,k;
    cin >> n >> m >> k;
    VVLL ru(n,VLL(m));
    REP(i,0,n) REP(j,0,m) ru[i][j] = i + j;
    REP(i,0,n) REP(j,1,m) ru[i][j] = (ru[i][j] + ru[i][j-1]) % MOD;
    REP(j,0,m) REP(i,1,n) ru[i][j] = (ru[i][j] + ru[i-1][j]) % MOD;

    CNK1 cnk;

    LL mul = 1;
    mul = cnk.get(n*m-2,k-2);
    LL ans = 0;
    REP(i,0,n) REP(j,0,m) {
        LL sum = 0;
        sum += ((1LL * i * (i + 1) / 2) % MOD) * m % MOD;
        if (sum >= MOD) sum -= MOD;
        sum += ((1LL * (n - 1 - i) * (n - 1 - i + 1) / 2) % MOD) * m % MOD;
        if (sum >= MOD) sum -= MOD;
        sum += ((1LL * j * (j + 1) / 2) % MOD) * n % MOD;
        if (sum >= MOD) sum -= MOD;
        sum += ((1LL * (m - 1 - j) * (m - 1 - j + 1) / 2) % MOD) * n % MOD;
        if (sum >= MOD) sum -= MOD;

        ans += sum;
        if (ans >= MOD) ans -= MOD;
    }
    ans = (ans * mul) % MOD;
    ans = (ans * power(2, MOD-2)) % MOD;
    cout << ans << endl;
}

signed main() {
    solve();
    
    return 0;
}