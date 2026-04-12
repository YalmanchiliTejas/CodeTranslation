#pragma GCC optimize("O3", "unroll-loops")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
#define ull unsigned long long
#define si short int
#define ll long long
#define ld long double
#define pb push_back
#define pii pair<int, int>
#define pil pair<int, ll>
#define pli pair<ll, int>
#define pll pair<ll, ll>
#define piii pair<pair<int, int>, int>
#define all(vec) vec.begin(), vec.end()
#define piiii pair<pair<int, int>, pair<int, int>>
#define fr(a, from, c) for(int a=(from); (a)<(c); (a)++)

/*-----------------------------------------------------SegTree---------------------------------------------*/
int mxn11 = (int) (2e5 + 1);
vector<ll> t(4 * mxn11 + 1, 0);
vector<ll> tAdd(4 * mxn11 + 1, 0);

void build(int v, int vl, int vr) {
    if (vl == vr) {
        t[v] = vl;
    } else {
        int tmp = (vl + vr) >> 1;
        build(2 * v, vl, tmp);
        build(2 * v + 1, tmp + 1, vr);
        t[v] = max(t[2 * v], t[2 * v + 1]);
    }
}

/* void push(int v) {
     tAdd[2 * v] += tAdd[v];
     tAdd[2 * v + 1] += tAdd[v];
     t[v] += tAdd[v];
     tAdd[v] = 0;
 }*/

int get(int v, int vl, int vr, int l, int r) {
    if (l > r) return 0;
    if (vl == l && vr == r) {
        return t[v] + tAdd[v];
    }
    int tmp = (vl + vr) >> 1;
    // push(v);
    ll a = get(2 * v, vl, tmp, l, min(tmp, r));
    ll b = get(2 * v + 1, tmp + 1, vr, max(tmp + 1, l), r);
    return max(a, b);
}

void update(int v, int vl, int vr, int pos, int cnt) {
    if (vl == vr) {
        t[v] = cnt;
        return;
    }
    int tmp = (vl + vr) >> 1;
    //push(v);
    if (pos <= tmp) {
        update(2 * v, vl, tmp, pos, cnt);
    } else {
        update(2 * v + 1, tmp + 1, vr, pos, cnt);
    }
    t[v] = max(t[2 * v], t[2 * v + 1]);
}

/*-----------------------------------------------------SegTree---------------------------------------------*/
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

/*-----------------------------------------------------MATH------------------------------------------------*/
inline ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

inline ll pwm(ll xx, ll pow, ll MD) {
    if (pow < 0) { pow = pow % (MD - 1) + MD - 1; }
    ll mlt = 1;
    while (pow) {
        if (pow & 1) {
            mlt *= xx;
            mlt %= MD;
        }
        xx *= xx;
        pow >>= 1;
        xx %= MD;
    }
    return mlt;
}

inline ll gcdex(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll xx, yy;
    ll gc = gcdex(b, a % b, yy, xx);
    x = xx;
    y = yy - (a / b) * xx;
    return gc;
}

inline int inv(ll r, int _mod) { return pwm(r % _mod, _mod - 2, _mod); }

inline int64_t hilbertOrder(int x, int y, int pow, int rotate) {
    if (pow == 0) {
        return 0;
    }
    int hpow = 1 << (pow - 1);
    int seg = (x < hpow) ? (
            (y < hpow) ? 0 : 3
    ) : (
                      (y < hpow) ? 1 : 2
              );
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int64_t subSquareSize = int64_t(1) << (2 * pow - 2);
    int64_t ans = seg * subSquareSize;
    int64_t add = hilbertOrder(nx, ny, pow - 1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ans;
}

/*-----------------------------------------------------MATH------------------------------------------------*/
vector<vector<int>> vert;
vector<int> x;
vector<pair<int, int>> d;
vector<int> ri;
vector<ll> dp;
ll mod = 998244353;

void solve() {
    string s;
    cin>>s;
    if(s=="AAA" || s=="BBB") cout<<"No";
    else cout<<"Yes";

}

int main() {
    /* ios::sync_with_stdio(false);
     cin.tie(nullptr);*/
    //freopen("C:\\Users\\Maximus\\CLionProjects\\Codeforces\\BestTeam\\output.txt", "r", stdin);
    //freopen("C:\\Users\\Maximus\\CLionProjects\\Codeforces\\BestTeam\\output.txt", "w", stdout);
    unsigned int beg_time = clock();

    int n = 1;
    for (int i = 0; i < n; i++) solve();


    unsigned int end_time = clock();
    //  cout<<endl<<endl<<end_time-beg_time;

    return 0;
}