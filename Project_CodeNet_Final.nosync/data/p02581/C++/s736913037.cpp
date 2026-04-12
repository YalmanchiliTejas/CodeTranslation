#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<P, ll> T;
typedef pair<long double , ll> Ps;
typedef pair<ll, bool> Pb;

const ll INF = 1e18;
const ll fact_table = 3200008;
long double Pi = 3.1415926535897932384626;

priority_queue <ll> pql;
priority_queue <P> pqp;
priority_queue <P> bag;
//big priority queue
priority_queue <ll, vector<ll>, greater<ll> > pqls;
priority_queue <P, vector<P>, greater<P> > pqps;
//small priority queue
//top pop

ll dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
ll dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};
//↓,→,↑,←


#define endl "\n"
#ifdef ENJAPMA
#undef endl
#endif

#define p(x) cout<<x<<endl;
#define el cout<<endl;
#define pe(x) cout<<x<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<(x);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define CLEAR(a) a = decltype(a)();
#define pc(x) cout << x << ",";
#define rep(i, n) for (ll i = 0; i < (n); i ++)

// const ll mod = 998244353ll;
const ll mod = 1000000007ll;

ll mypow(ll a, ll b, ll mod) {ll x = 1; while (b) {while (!(b & 1)) {(a *= a) %= mod; b >>= 1;}(x *= a) %= mod; b--;} return x;}
void YES(bool cond) { if (cond) { p("YES");} else { p("NO");} return;}
void Yes(bool cond) { if (cond) { p("Yes");} else { p("No");} return;}
void line() { p("--------------------"); return;}

/*
ll fact[fact_table + 5], rfact[fact_table + 5];

void c3_init() {
    fact[0] = rfact[0] = 1;
    for (ll i = 1; i <= fact_table; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    rfact[fact_table] = mypow(fact[fact_table], mod - 2, mod);
    for (ll i = fact_table; i >= 1; i--) {
        rfact[i - 1] = rfact[i] * i;
        rfact[i - 1] %= mod;
    }
    return;
}
ll c3(ll n, ll r) {
    return (((fact[n] * rfact[r]) % mod ) * rfact[n - r]) % mod;
}
*/
struct Timer {
    int64_t start;
    const int64_t CYCLES_PER_SEC = 2800000000;
    Timer() { reset(); }
    void reset() { start = getCycle(); }
    inline double get() { return (double)(getCycle() - start) / CYCLES_PER_SEC; }
    inline int64_t getCycle() {
        uint32_t low, high;
        __asm__ volatile ("rdtsc" : "=a" (low), "=d" (high));
        return ((int64_t)low) | ((int64_t)high << 32);
    }
};


bool multicase = false;

ll n, m, k, w, num, a, b, c, d, e, h, q, ans, sum, l;

typedef vector<ll> vec;
typedef vector<vector<ll>> mat;
string s[1005];
ll dp[2][2005][2005];
ll max_table[2005][2005];
ll all_max[2005];
vector<P> updated;

void update(ll time, ll a, ll b, ll value) {
    dp[time%2][a][b] = dp[time%2][b][a] = max(dp[time%2][a][b], value);
    max_table[time][a] = max(max_table[time][a], value);
    max_table[time][b] = max(max_table[time][b], value);
    all_max[time] = max(all_max[time], dp[time%2][a][b]);
    all_max[time] = max(all_max[time], all_max[time-1]);
    updated.pb(P(a, b));
    updated.pb(P(b, a));
    return;
}


void solve() {
    cin >> n;
    vec x(3 * n);
    for (int i = 0; i < 3 * n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[0][i][j] = dp[1][i][j] = -INF;
        }
        all_max[i] = -INF;
    }
    for(int i=0;i<=n;i++){
        for(int j=1;j<=n;j++){
            max_table[i][j] = -INF;
        }
    }
    dp[0][x[0]][x[1]] = 0;
    dp[0][x[1]][x[0]] = 0;
    dp[1][x[0]][x[1]] = 0;
    dp[1][x[1]][x[0]] = 0;
    all_max[0] = 0;
    all_max[1] = 0;
    max_table[0][x[0]] = max_table[0][x[1]] = 0;
    max_table[1][x[0]] = max_table[1][x[1]] = 0;
    /*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            pe(dp[0][i][j]);
        }
        el;
    }
    */
    ll bonus = 0;
    for (int i = 0; i < n - 1; i++) {
        vec y(3);
        y[0] = x[2 + 3 * i], y[1] = x[3 + 3 * i], y[2] = x[4 + 3 * i];
        sort(y.begin(), y.end());
        a = y[0], b = y[1], c = y[2];
        if (a == b && b == c) {
            bonus ++;
        } else if (a < b && b < c) {
            update(i+1, a, b, max(dp[i%2][c][c] + 1, all_max[i]));
            update(i+1, b, c, max(dp[i%2][a][a] + 1, all_max[i]));
            update(i+1, a, c, max(dp[i%2][b][b] + 1, all_max[i]));
            for (int j = 1; j <= n; j++) {
                // 片方がjであるようなものの最大値を持ってくる
                ll maxi = max_table[i][j];
                update(i+1, a, j, maxi);
                update(i+1, b, j, maxi);
                update(i+1, c, j, maxi);
            }
        } else if (a == b && b < c) {
            // (a, a, c)

            update(i+1, a, b, max(dp[i%2][c][c] + 1, all_max[i]));
            update(i+1, b, c, max(dp[i%2][a][a] + 1, all_max[i]));
            update(i+1, a, c, max(dp[i%2][b][b] + 1, all_max[i]));
            // (a, c)を使う場合
            for (int j = 1; j <= n; j++) {
                ll maxi = max_table[i][j];
                update(i+1, a, j, maxi);
            }

            // (a, a)を使う場合
            for (int j = 1; j <= n; j++) {
                // (a, j) -> (c, j) への遷移
                update(i+1, c, j, dp[i%2][a][j] + 1);
            }

            for (int j = 1; j <= n; j++) {
                // (*, j) -> (c, j) への遷移
                ll maxi = max_table[i][j];
                update(i+1, c, j, maxi);
            }
        } else if (a < b && b == c) {
            update(i+1, a, b, max(dp[i%2][c][c] + 1, all_max[i]));
            update(i+1, b, c, max(dp[i%2][a][a] + 1, all_max[i]));
            update(i+1, a, c, max(dp[i%2][b][b] + 1, all_max[i]));
            for (int j = 1; j <= n; j++) {
                ll maxi = max_table[i][j];
                update(i+1, b, j, maxi);
            }
            for (int j = 1; j <= n; j++) {
                update(i+1, a, j, dp[i%2][c][j] + 1);
            }
            for (int j = 1; j <= n; j++) {
                ll maxi = max_table[i][j];
                update(i+1, a, j, maxi);
            }
        }
        for(auto u : updated){
            int a = u.first, b = u.second;
            dp[i%2][a][b] = max(dp[i%2][a][b], dp[(i+1)%2][a][b]);
        }
        for(int j=1;j<=n;j++){
            max_table[i%2][j] = max_table[(i+1)%2][j];
        }
        all_max[i+2] = all_max[i+1];
        updated.clear();
        /*
        line();
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                pe(dp[(i+1)%2][j][k]);
            }
            el;
        }
        line();
        */
    }
    ll last = x.back();
    all_max[n-1] = max(all_max[n-1], dp[(n-1)%2][last][last] + 1);
    p(all_max[n-1] + bonus);

    return;
}

int main() {
    // init();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll q, testcase = 1;
    if (multicase) {
        cin >> q;
    } else {
        q = 1;
    }
    while (q--) {
        // pu("Case ");pu("#");pu(testcase);pu(": ");
        solve();
        testcase++;
    }
    // solve();
    return 0;
}

