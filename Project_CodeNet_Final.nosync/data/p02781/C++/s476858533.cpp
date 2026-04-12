#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#include<functional>
#include<map>
#include<iomanip>
#include<limits>
#include<unordered_set> 
#include<cmath>
#include <numeric>
#include <array>
#include <complex>
using namespace std;
//long long p = 998244353;
long long p = 1000000007;
#define int long long
#define ll long long
#define vel vector<ll>
#define vvel vector<vel>
#define rep(i,n) for(int i=0;i<n;i++)
#define sor(v) sort(v.begin(),v.end())
#define mmax(a,b) a=max(a,b)
#define mmin(a,b) a=min(a,b)
#define mkp make_pair
#define pin pair<int,int>
#define qin pair<pin,int>
#define V vector
#define Endl endl
#define veb vector<bool>
#define fcout cout << fixed << setprecision(15)
#define rev(s) reverse(s.begin(),s.end())
#define lower(h,val) lower_bound(h.begin(),h.end(),val)-h.begin()
#define upper(h,val) upper_bound(h.begin(),h.end(),val)-h.begin()
vel kai;
vel inv_kai;
int rui(int a, int n, int mod) {
    if (n == 0) { return 1 % mod; }
    int x = rui(a, n / 2, mod);
    x *= x; x %= mod;
    if (n % 2 == 1) { x *= a; x %= mod; }
    return x;
}
int root(int x, vel& pa) {
    if (pa[x] == -1) { return x; }
    int ans = root(pa[x], pa); pa[x] = ans;
    return ans;
}
bool mar(int x, int y, vel& pa) {
    x = root(x, pa);
    y = root(y, pa);
    if (x != y) { pa[x] = y; }
    return (x != y);
}
int gcd(int x, int y) {
    if (x < y) { return gcd(y, x); }
    if (y == 0) { return x; }
    return gcd(y, x % y);
}
int lcm(ll x, ll y) {
    x = abs(x); y = abs(y);
    return x * y / gcd(x, y);
}
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
void make_kai(int max_kai) {
    kai = vel(max_kai, 1);
    inv_kai = kai;
    rep(i, max_kai - 1) {
        kai[i + 1] = kai[i] * (i + 1); kai[i + 1] %= p;
        inv_kai[i + 1] = modinv(kai[i + 1], p);
    }
}
int com(int n, int r) {
    if ((n < 0) || (r < 0) || (r > n)) { return 0; }
    int ans = (kai[n] * inv_kai[r]) % p;
    return (ans * inv_kai[n - r]) % p;
}
vel uni(vel x) {
    if (x.size() == 0) { return x; }
    sor(x);
    int n = x.size();
    vel ans(1, x[0]);
    for (int j = 1; j < n; j++) {
        if (x[j - 1] != x[j]) { ans.push_back(x[j]); }
    }
    x = ans;
    return x;
}
void pr(vel& v) {
    int n = v.size();
    if (n != 0) {
        cout << v[0];
        rep(i, n - 1) {
            cout << " " << v[i + 1];
        }
        cout << endl;
    }
}
vel dijk(V<V<pin>>& way, int st, int inf) {
    int n = way.size();
    vel dist(n, inf); dist[st] = 0;
    priority_queue<pin, vector<pin>, greater<pin>> pq;
    pq.push(mkp(0, st));
    veb is_checked(n, false);
    while (!pq.empty()) {
        pin x = pq.top(); pq.pop();
        int pot = x.second;
        if (!is_checked[pot]) {
            is_checked[pot] = true;
            for (auto y : way[pot]) {
                int nex_dist = x.first + y.second;
                int nex_pot = y.first;
                if (dist[nex_pot] > nex_dist) {
                    dist[nex_pot] = nex_dist;
                    pq.push(mkp(nex_dist, y.first));
                }
            }
        }
    }
    return dist;
}
vel mul(vel& a, vel& b) {
    int n = a.size();
    int m = b.size();
    vel ans(n + m - 1, 0);
    rep(i, n) {
        rep(j, m) {
            ans[i + j] += a[i] * b[j];
            ans[i + j] %= p;
        }
    }
    return ans;
}
vel rui_p(vel& a, int n) {
    if (n == 0) { return { 1 }; }
    vel qans = rui_p(a, n / 2);
    qans = mul(qans, qans);
    if (n % 2 == 1) {
        qans = mul(qans, a);
    }
    return qans;
}
bool is_prime(int n) {
    if (n == 0 || n == 1) { return false; }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) { return false; }
    }
    return true;
}
#define bs bitset<50>
void per(int& ans) {
    ans %= p;
    if (ans < 0) { ans += p; }
}
int count_zero(V<bs>& a) {
    int n = a.size();
    int now_st = 0;
    rep(i, 300) {

        int fir_ze = -1;
        for (int j = now_st; j < n; j++) {
            if (a[j][i]) { fir_ze = j; break; }
        }
        if (fir_ze >= 0) {
            rep(j, n) {
                if (j != fir_ze && a[j][i]) {
                    a[j] = a[fir_ze] xor a[j];
                }
            }
            swap(a[now_st], a[fir_ze]);
            now_st++;
        }
    }
    int ans = 0;
    rep(i, n) {
        bool fl = true;
        rep(j, 300) {
            if (a[i][j]) { fl = false; break; }
        }
        if (fl) { ans++; }
    }
    return ans;
}
#define upperbound(v,val) upper_bound(v.begin(),v.end(),val)-v.begin();
#define lowerbound(v,val) lower_bound(v.begin(),v.end(),val)-v.begin();
#define mat V<V<pin>>
int inf = 10000;
int linf = 10000;
pin p_mul(pin a, pin b) {
    pin c = mkp(max(b.first, a.first + b.second), a.second + b.second);
    return c;
}
mat m_mul(mat& a, mat& b) {
    int n = a.size();
    mat c(n, V<pin>(n, mkp(-inf, -inf)));
    int ze = 0;
    rep(i, n) {
        rep(j, n) {
            rep(k, n) {
                if (a[i][j].second > -linf && b[j][k].second > -linf) {
                    pin x = p_mul(a[i][j], b[j][k]);
                    mmax(c[i][k].first, x.first);
                    mmax(c[i][k].second, x.second);
                    mmax(c[i][k].first, ze);
                }
            }
        }
    }
    return c;
}
vvel disj_min(vel& v) {
    int n = v.size();
    vvel ret(22, vel(n));
    ret[0] = v;
    rep(i, 21) {
        rep(j, n) {
            int nex = j + (1 << i);
            if (nex < n) {
                ret[i + 1][j] = min(ret[i][j], ret[i][nex]);
            }
            else {
                ret[i + 1][j] = ret[i][j];
            }
        }
    }
    return ret;
}
vvel disj_max(vel& v) {
    int n = v.size();
    vvel ret(20, vel(n));
    ret[0] = v;
    rep(i, 19) {
        rep(j, n) {
            int nex = j + (1 << i);
            if (nex < n) {
                ret[i + 1][j] = max(ret[i][j], ret[i][nex]);
            }
            else {
                ret[i + 1][j] = ret[i][j];
            }
        }
    }
    return ret;
}
int find_min(vvel& dv, int l, int r) {
    int i = 19;
    while (l + (1 << i) > r) {
        i--;
    }
    return min(dv[i][l], dv[i][r - (1 << i)]);
}
int find_max(vvel& dv, int l, int r) {
    int i = 19;
    while (l + (1 << i) > r) {
        i--;
    }
    return max(dv[i][l], dv[i][r - (1 << i)]);
}
void pri(int x, int y, int z, int w) {
    cout << x << "," << 500 << "," << 60 << "," << 60 << ",";
    cout << y << "," << 500 << "," << 60 << "," << 60;
    rep(i, 5) {
        if (i != z) { cout << "," << 0; }
        else { cout << "," << w; }
    }
    cout << endl;
}
int dp[4][101][4];
int solve(string s, int n, int k, bool fl) {
    bool fl2 = false;
    if (n > 0 && s[0] == ':') { fl2 = true; }
    int ind = 0;
    if (fl) { ind++; }
    if (fl2) { ind += 2; }
    if (dp[ind][n][k] == -1) {
        int ans = 0;
        if (k >= 0) {
            if (n == 0) {
                if (!fl && k == 0) { ans = 1; }
            }
            else {
                for (int i = 0; i <= min(s[0] - '0', 9); i++) {
                    string t = "";
                    if (n > 1) {
                        rep(j, n - 1) { t += s[j + 1]; }
                        if (s[0] - '0' > i) {
                            t[0] = '9'; t[0]++;
                        }
                    }
                    if (i == 0) { ans += solve(t, n - 1, k, fl); }
                    else { ans += solve(t, n - 1, k - 1, false); }
                }
            }
        }
        dp[ind][n][k] = ans;
    }
    return dp[ind][n][k];
}
signed main() {
    string s; cin >> s;
    int n = s.size();
    int k; cin >> k;
    bool fl = true;
    rep(i, 4) {
        rep(j, 101) {
            rep(k, 4) {
                dp[i][j][k] = -1;
            }
        }
    }
    cout << solve(s, n, k,fl) << endl;
}
